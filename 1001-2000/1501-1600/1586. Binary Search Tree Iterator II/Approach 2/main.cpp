struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    vector<int> history;
    stack<TreeNode*> traversalStack;
    TreeNode* currentTraversalNode;
    int cursor;

public:
    BSTIterator(TreeNode* root) : currentTraversalNode(root), cursor(-1) {}

    bool hasNext() {
        return cursor + 1 < static_cast<int>(history.size()) || !traversalStack.empty() || currentTraversalNode != nullptr;
    }

    int next() {
        cursor++;
        if (cursor < static_cast<int>(history.size())) {
            return history[cursor];
        }
        while (currentTraversalNode != nullptr) {
            traversalStack.push(currentTraversalNode);
            currentTraversalNode = currentTraversalNode->left;
        }
        currentTraversalNode = traversalStack.top();
        traversalStack.pop();
        int val = currentTraversalNode->val;
        history.push_back(val);
        currentTraversalNode = currentTraversalNode->right;
        return val;
    }

    bool hasPrev() {
        return cursor > 0;
    }

    int prev() {
        cursor--;
        return history[cursor];
    }
};
