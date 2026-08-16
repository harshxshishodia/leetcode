struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
    unordered_set<int> recoveredSet;

    void recoverTree(TreeNode* node, int currentValue) {
        if (!node) return;
        node->val = currentValue;
        recoveredSet.insert(currentValue);
        recoverTree(node->left, 2 * currentValue + 1);
        recoverTree(node->right, 2 * currentValue + 2);
    }

public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }

    bool find(int target) {
        return recoveredSet.count(target);
    }
};
