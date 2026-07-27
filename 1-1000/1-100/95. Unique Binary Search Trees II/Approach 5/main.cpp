// Approach 5: Bottom-up interval dynamic programming

class Solution {
public:
    // O(n * Cn) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<vector<TreeNode*>>> intervalTrees(
            n + 2,
            vector<vector<TreeNode*>>(n + 2)
        );

        vector<TreeNode*> emptySubtree = {
            nullptr
        };

        for (int length = 1; length <= n; length++) {
            for (
                int startValue = 1;
                startValue + length - 1 <= n;
                startValue++
            ) {
                int endValue = startValue + length - 1;

                for (
                    int rootValue = startValue;
                    rootValue <= endValue;
                    rootValue++
                ) {
                    const vector<TreeNode*>& leftSubtrees =
                        rootValue == startValue
                            ? emptySubtree
                            : intervalTrees[startValue][rootValue - 1];

                    const vector<TreeNode*>& rightSubtrees =
                        rootValue == endValue
                            ? emptySubtree
                            : intervalTrees[rootValue + 1][endValue];

                    for (TreeNode* leftSubtree : leftSubtrees) {
                        for (TreeNode* rightSubtree : rightSubtrees) {
                            TreeNode* root = new TreeNode(rootValue);

                            root->left = leftSubtree;
                            root->right = rightSubtree;

                            intervalTrees[startValue][endValue]
                                .push_back(root);
                        }
                    }
                }
            }
        }

        return intervalTrees[1][n];
    }
};