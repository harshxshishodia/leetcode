// Approach 1: Generate all unique BSTs and return the vector size

class Solution {
private:
    struct GeneratedTreeNode {
        int value;
        GeneratedTreeNode* left;
        GeneratedTreeNode* right;

        GeneratedTreeNode(int nodeValue) {
            value = nodeValue;
            left = nullptr;
            right = nullptr;
        }
    };

    vector<GeneratedTreeNode*> buildTrees(int startValue, int endValue) {
        if (startValue > endValue) {
            return {nullptr};
        }

        vector<GeneratedTreeNode*> allTrees;

        for (int rootValue = startValue; rootValue <= endValue; rootValue++) {
            vector<GeneratedTreeNode*> leftSubtrees = buildTrees(startValue, rootValue - 1);
            vector<GeneratedTreeNode*> rightSubtrees = buildTrees(rootValue + 1, endValue);

            for (GeneratedTreeNode* leftSubtree : leftSubtrees) {
                for (GeneratedTreeNode* rightSubtree : rightSubtrees) {
                    GeneratedTreeNode* root = new GeneratedTreeNode(rootValue);

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
    int numTrees(int n) {
        vector<GeneratedTreeNode*> allTrees = buildTrees(1, n);
        return allTrees.size();
    }
};