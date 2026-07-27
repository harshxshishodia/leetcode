// Approach 4: Recursive divide and conquer with memoization

class Solution {
private:
    map<pair<int, int>, vector<TreeNode*>> memo;

    vector<TreeNode*> buildTrees(int startValue, int endValue) {
        if (startValue > endValue) {
            return {nullptr};
        }

        pair<int, int> currentRange = {startValue,endValue};

        if (memo.find(currentRange) != memo.end()) {
            return memo[currentRange];
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

        memo[currentRange] = allTrees;

        return memo[currentRange];
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