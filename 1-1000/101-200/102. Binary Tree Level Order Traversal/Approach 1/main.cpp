// Approach 1: Calculate the height and collect every level separately
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

    void collectCurrentLevel(
        TreeNode* currentNode,
        int targetLevel,
        vector<int>& levelValues
    ) {
        if (currentNode == nullptr) {
            return;
        }

        if (targetLevel == 1) {
            levelValues.push_back(currentNode->val);
            return;
        }

        collectCurrentLevel(
            currentNode->left,
            targetLevel - 1,
            levelValues
        );

        collectCurrentLevel(
            currentNode->right,
            targetLevel - 1,
            levelValues
        );
    }

public:
    // O(nh) | O(h)
    // Worst-case time: O(n^2)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        int treeHeight = calculateHeight(root);

        for (
            int currentLevel = 1;
            currentLevel <= treeHeight;
            currentLevel++
        ) {
            vector<int> levelValues;

            collectCurrentLevel(
                root,
                currentLevel,
                levelValues
            );

            levelOrderTraversal.push_back(levelValues);
        }

        return levelOrderTraversal;
    }
};