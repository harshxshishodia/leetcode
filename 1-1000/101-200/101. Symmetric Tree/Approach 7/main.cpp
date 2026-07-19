class Solution {
public:
    void mirror(TreeNode* root) {
        if (!root)
            return;

        swap(root->left, root->right);

        mirror(root->left);
        mirror(root->right);
    }

    bool same(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;

        if (!a || !b)
            return false;

        return a->val == b->val && same(a->left, b->left) && same(a->right, b->right);
    }
    
    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        mirror(root->right);

        return same(root->left, root->right);
    }
};