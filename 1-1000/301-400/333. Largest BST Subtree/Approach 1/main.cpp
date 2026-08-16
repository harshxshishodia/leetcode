class Solution {
    bool valid(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= lower || root->val >= upper) {
            return false;
        }

        return valid(root->left, lower, root->val) &&
               valid(root->right, root->val, upper);
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 +
               countNodes(root->left) +
               countNodes(root->right);
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        if (valid(
                root,
                numeric_limits<long long>::min(),
                numeric_limits<long long>::max())) {
            return countNodes(root);
        }

        return max(
            largestBSTSubtree(root->left),
            largestBSTSubtree(root->right)
        );
    }
};
