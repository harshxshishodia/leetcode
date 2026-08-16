class Solution {
    unordered_map<int, vector<TreeNode*>> memo;

    vector<TreeNode*> solve(int n) {
        auto found =
            memo.find(n);

        if (found != memo.end()) {
            return found->second;
        }

        if (n == 1) {
            return {
                new TreeNode(0)
            };
        }

        vector<TreeNode*> answer;

        for (int leftNodes = 1;
             leftNodes < n;
             leftNodes += 2) {
            int rightNodes =
                n - 1 - leftNodes;

            vector<TreeNode*> leftTrees =
                solve(leftNodes);

            vector<TreeNode*> rightTrees =
                solve(rightNodes);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root =
                        new TreeNode(0);

                    root->left = left;
                    root->right = right;

                    answer.push_back(root);
                }
            }
        }

        memo[n] = answer;
        return memo[n];
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        memo.clear();

        return solve(n);
    }
};
