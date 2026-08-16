struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    vector<int> inorderValues;
    int currentIndex;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderValues.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) : currentIndex(-1) {
        inorder(root);
    }

    bool hasNext() {
        return currentIndex + 1 < static_cast<int>(inorderValues.size());
    }

    int next() {
        return inorderValues[++currentIndex];
    }

    bool hasPrev() {
        return currentIndex > 0;
    }

    int prev() {
        return inorderValues[--currentIndex];
    }
};
