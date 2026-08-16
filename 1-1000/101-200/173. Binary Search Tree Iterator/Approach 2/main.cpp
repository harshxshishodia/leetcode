struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode*> traversalStack;

    void pushLeftChain(TreeNode* node) {
        while (node != nullptr) {
            traversalStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeftChain(root);
    }

    int next() {
        TreeNode* topNode = traversalStack.top();
        traversalStack.pop();
        if (topNode->right != nullptr) {
            pushLeftChain(topNode->right);
        }
        return topNode->val;
    }

    bool hasNext() {
        return !traversalStack.empty();
    }
};
