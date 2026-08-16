class Solution {
    struct Info {
        bool bst;
        long long minimum;
        long long maximum;
        int size;
    };

    Info solve(TreeNode* root) {
        if (root == nullptr) {
            return {
                true,
                numeric_limits<long long>::max(),
                numeric_limits<long long>::min(),
                0
            };
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if (left.bst &&
            right.bst &&
            root->val > left.maximum &&
            root->val < right.minimum) {
            return {
                true,
                min<long long>(left.minimum, root->val),
                max<long long>(right.maximum, root->val),
                left.size + right.size + 1
            };
        }

        return {
            false,
            numeric_limits<long long>::min(),
            numeric_limits<long long>::max(),
            max(left.size, right.size)
        };
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        return solve(root).size;
    }
};
