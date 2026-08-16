struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    vector<int> inorderNodes;
    int currentIndex;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        inorderNodes.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) : currentIndex(0) {
        inorder(root);
    }

    int next() {
        return inorderNodes[currentIndex++];
    }

    bool hasNext() {
        return currentIndex < static_cast<int>(inorderNodes.size());
    }
};
