class Solution {
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        int take = root->val + left.second + right.second;
        int skip = max(left.first, left.second) +
                   max(right.first, right.second);

        return {take, skip};
    }

public:
    int rob(TreeNode* root) {
        auto result = solve(root);
        return max(result.first, result.second);
    }
};
