// Approach 1: Calculate tree height and collect every level separately
// Genuine brute-force approach

class Solution {
private:
    int calculateHeight(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return 0;
        }

        int leftHeight = calculateHeight(currentNode->left);
        int rightHeight = calculateHeight(currentNode->right);

        return 1 + max(leftHeight, rightHeight);
    }

    void collectLevel(
        TreeNode* currentNode,
        int targetLevel,
        bool leftToRight,
        vector<int>& levelValues
    ) {
        if (currentNode == nullptr) {
            return;
        }

        if (targetLevel == 1) {
            levelValues.push_back(currentNode->val);
            return;
        }

        if (leftToRight) {
            collectLevel(
                currentNode->left,
                targetLevel - 1,
                leftToRight,
                levelValues
            );

            collectLevel(
                currentNode->right,
                targetLevel - 1,
                leftToRight,
                levelValues
            );
        } else {
            collectLevel(
                currentNode->right,
                targetLevel - 1,
                leftToRight,
                levelValues
            );

            collectLevel(
                currentNode->left,
                targetLevel - 1,
                leftToRight,
                levelValues
            );
        }
    }

public:
    // O(nh) | O(h)
    // Worst-case time: O(n^2)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;

        int treeHeight = calculateHeight(root);

        for (int currentLevel = 1; currentLevel <= treeHeight; currentLevel++) {
            vector<int> levelValues;

            bool leftToRight = currentLevel % 2 == 1;

            collectLevel(
                root,
                currentLevel,
                leftToRight,
                levelValues
            );

            zigzagTraversal.push_back(levelValues);
        }

        return zigzagTraversal;
    }
};