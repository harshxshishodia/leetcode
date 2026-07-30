// Approach 4: Standard BFS and reverse alternate levels

class Solution {
public:
    // O(n) | O(w)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;

        if (root == nullptr) {
            return zigzagTraversal;
        }

        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);

        bool leftToRight = true;

        while (!pendingNodes.empty()) {
            int currentLevelSize = pendingNodes.size();

            vector<int> levelValues;

            for (int processedNodes = 0; processedNodes < currentLevelSize; processedNodes++) {
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

            if (!leftToRight) {
                reverse(
                    levelValues.begin(),
                    levelValues.end()
                );
            }

            zigzagTraversal.push_back(levelValues);
            leftToRight = !leftToRight;
        }

        return zigzagTraversal;
    }
};