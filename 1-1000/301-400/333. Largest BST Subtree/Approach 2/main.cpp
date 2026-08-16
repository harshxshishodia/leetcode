class Solution {
    struct Bounds {
        bool bst;
        long long minimum;
        long long maximum;
        int size;
    };

    unordered_map<TreeNode*, Bounds> memo;

    Bounds analyze(TreeNode* root) {
        if (root == nullptr) {
            return {
                true,
                numeric_limits<long long>::max(),
                numeric_limits<long long>::min(),
                0
            };
        }

        auto found = memo.find(root);

        if (found != memo.end()) {
            return found->second;
        }

        Bounds left = analyze(root->left);
        Bounds right = analyze(root->right);

        if (left.bst &&
            right.bst &&
            root->val > left.maximum &&
            root->val < right.minimum) {
            Bounds current = {
                true,
                min<long long>(left.minimum, root->val),
                max<long long>(right.maximum, root->val),
                left.size + right.size + 1
            };

            memo[root] = current;
            return current;
        }

        Bounds current = {
            false,
            numeric_limits<long long>::min(),
            numeric_limits<long long>::max(),
            max(left.size, right.size)
        };

        memo[root] = current;
        return current;
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        return analyze(root).size;
    }
};
