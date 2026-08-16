class Solution {
    TreeNode* cloneWithOffset(TreeNode* root, int offset) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* copy = new TreeNode(root->val + offset);
        copy->left = cloneWithOffset(root->left, offset);
        copy->right = cloneWithOffset(root->right, offset);
        return copy;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<TreeNode*>> dp(n + 1);
        dp[0] = {nullptr};

        for (int nodes = 1; nodes <= n; nodes++) {
            for (int leftCount = 0; leftCount < nodes; leftCount++) {
                int rightCount = nodes - 1 - leftCount;
                int rootValue = leftCount + 1;

                for (TreeNode* leftTree : dp[leftCount]) {
                    for (TreeNode* rightTree : dp[rightCount]) {
                        TreeNode* root = new TreeNode(rootValue);
                        root->left = cloneWithOffset(leftTree, 0);
                        root->right = cloneWithOffset(rightTree, rootValue);
                        dp[nodes].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }
};
