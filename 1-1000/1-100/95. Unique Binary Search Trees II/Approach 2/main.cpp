class Solution {
    map<pair<int, int>, vector<TreeNode*>> memo;

    vector<TreeNode*> build(int left, int right) {
        if (left > right) {
            return {nullptr};
        }

        pair<int, int> key = {left, right};

        if (memo.count(key)) {
            return memo[key];
        }

        vector<TreeNode*> trees;

        for (int rootValue = left; rootValue <= right; rootValue++) {
            vector<TreeNode*> leftTrees = build(left, rootValue - 1);
            vector<TreeNode*> rightTrees = build(rootValue + 1, right);

            for (TreeNode* leftTree : leftTrees) {
                for (TreeNode* rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(rootValue);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }

        memo[key] = trees;
        return memo[key];
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        return build(1, n);
    }
};
