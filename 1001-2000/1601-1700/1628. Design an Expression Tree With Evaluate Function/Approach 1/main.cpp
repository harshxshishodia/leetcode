class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
};

class NumericNode : public Node {
    int value;
public:
    NumericNode(int v) : value(v) {}
    int evaluate() const override {
        return value;
    }
};

class OperatorNode : public Node {
    char op;
    Node* leftChild;
    Node* rightChild;
public:
    OperatorNode(char o, Node* left, Node* right) : op(o), leftChild(left), rightChild(right) {}
    ~OperatorNode() {
        delete leftChild;
        delete rightChild;
    }
    int evaluate() const override {
        int leftVal = leftChild->evaluate();
        int rightVal = rightChild->evaluate();
        switch (op) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return leftVal / rightVal;
        }
        return 0;
    }
};

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> nodeStack;
        for (const string& token : postfix) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                Node* right = nodeStack.top(); nodeStack.pop();
                Node* left = nodeStack.top(); nodeStack.pop();
                nodeStack.push(new OperatorNode(token[0], left, right));
            } else {
                nodeStack.push(new NumericNode(stoi(token)));
            }
        }
        return nodeStack.top();
    }
};
