// Approach 4: Standard BFS using the number of nodes in each level

class Solution {
public:
    // O(n) | O(w)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        if (root == nullptr) {
            return levelOrderTraversal;
        }

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty()) {
            int currentLevelSize = pendingNodes.size();

            vector<int> levelValues;

            for (
                int processedNodes = 0;
                processedNodes < currentLevelSize;
                processedNodes++
            ) {
                TreeNode* currentNode = pendingNodes.front();
                pendingNodes.pop();

                levelValues.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    pendingNodes.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    pendingNodes.push(currentNode->right);
                }
            }

            levelOrderTraversal.push_back(levelValues);
        }

        return levelOrderTraversal;
    }
};