// Approach 3: Recursive divide and conquer

class Solution {
private:
    vector<TreeNode*> buildTrees(int startValue, int endValue) {
        if (startValue > endValue) {
            return {nullptr};
        }

        vector<TreeNode*> allTrees;

        for (int rootValue = startValue; rootValue <= endValue; rootValue++) {
            vector<TreeNode*> leftSubtrees = buildTrees(startValue, rootValue - 1);

            vector<TreeNode*> rightSubtrees = buildTrees(rootValue + 1, endValue);

            for (TreeNode* leftSubtree : leftSubtrees) {
                for (TreeNode* rightSubtree : rightSubtrees) {
                    TreeNode* root = new TreeNode(rootValue);

                    root->left = leftSubtree;
                    root->right = rightSubtree;

                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }

public:
    // O(n * Cn) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        return buildTrees(1, n);
    }
};