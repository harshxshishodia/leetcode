// Approach 5: BFS with direct placement at the correct index

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

            vector<int> levelValues(currentLevelSize);

            for (int processedNodes = 0; processedNodes < currentLevelSize; processedNodes++) {
                TreeNode* currentNode = pendingNodes.front();
                pendingNodes.pop();

                int insertionIndex;

                if (leftToRight) {
                    insertionIndex = processedNodes;
                } else {
                    insertionIndex = currentLevelSize - processedNodes - 1;
                }

                levelValues[insertionIndex] = currentNode->val;

                if (currentNode->left != nullptr) {
                    pendingNodes.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    pendingNodes.push(currentNode->right);
                }
            }

            zigzagTraversal.push_back(levelValues);
            leftToRight = !leftToRight;
        }

        return zigzagTraversal;
    }
};