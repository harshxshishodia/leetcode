class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
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
                allPossibleFBT(leftNodes);

            vector<TreeNode*> rightTrees =
                allPossibleFBT(rightNodes);

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

        return answer;
    }
};
