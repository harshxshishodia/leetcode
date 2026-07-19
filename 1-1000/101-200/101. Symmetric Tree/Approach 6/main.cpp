class Solution {
public:
    TreeNode* mirror(TreeNode* root) {
        if (!root)
            return nullptr;

        TreeNode* node = new TreeNode(root->val);

        node->left = mirror(root->right);
        node->right = mirror(root->left);

        return node;
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

        TreeNode* mirrorTree = mirror(root->right);

        return same(root->left, mirrorTree);
    }
};