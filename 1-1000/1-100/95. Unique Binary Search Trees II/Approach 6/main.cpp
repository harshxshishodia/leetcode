// Approach 6: Bottom-up dynamic programming by node count

class Solution {
private:
    TreeNode* cloneTree(TreeNode* root, int valueOffset) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* clonedRoot =
            new TreeNode(root->val + valueOffset);

        clonedRoot->left =
            cloneTree(root->left, valueOffset);

        clonedRoot->right =
            cloneTree(root->right, valueOffset);

        return clonedRoot;
    }

public:
    // O(n * Cn) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<TreeNode*>> treesByNodeCount(n + 1);

        treesByNodeCount[0].push_back(nullptr);

        for (
            int totalNodeCount = 1;
            totalNodeCount <= n;
            totalNodeCount++
        ) {
            for (
                int rootValue = 1;
                rootValue <= totalNodeCount;
                rootValue++
            ) {
                int leftNodeCount = rootValue - 1;
                int rightNodeCount =
                    totalNodeCount - rootValue;

                for (
                    TreeNode* leftPrototype :
                    treesByNodeCount[leftNodeCount]
                ) {
                    for (
                        TreeNode* rightPrototype :
                        treesByNodeCount[rightNodeCount]
                    ) {
                        TreeNode* root =
                            new TreeNode(rootValue);

                        root->left =
                            cloneTree(leftPrototype, 0);

                        root->right =
                            cloneTree(rightPrototype, rootValue);

                        treesByNodeCount[totalNodeCount]
                            .push_back(root);
                    }
                }
            }
        }

        return treesByNodeCount[n];
    }
};