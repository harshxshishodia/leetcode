class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int take = root->val;

        if (root->left != nullptr) {
            take += rob(root->left->left);
            take += rob(root->left->right);
        }

        if (root->right != nullptr) {
            take += rob(root->right->left);
            take += rob(root->right->right);
        }

        int skip = rob(root->left) + rob(root->right);

        return max(take, skip);
    }
};
