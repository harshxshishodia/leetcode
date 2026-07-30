// Approach 6: Direction-aware traversal using a deque

class Solution {
public:
    // O(n) | O(w)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;

        if (root == nullptr) {
            return zigzagTraversal;
        }

        deque<TreeNode*> pendingNodes;
        pendingNodes.push_back(root);

        bool leftToRight = true;

        while (!pendingNodes.empty()) {
            int currentLevelSize = pendingNodes.size();

            vector<int> levelValues;

            for (int processedNodes = 0; processedNodes < currentLevelSize; processedNodes++) {
                if (leftToRight) {
                    TreeNode* currentNode = pendingNodes.front();
                    pendingNodes.pop_front();

                    levelValues.push_back(currentNode->val);

                    if (currentNode->left != nullptr) {
                        pendingNodes.push_back(currentNode->left);
                    }

                    if (currentNode->right != nullptr) {
                        pendingNodes.push_back(currentNode->right);
                    }
                } else {
                    TreeNode* currentNode = pendingNodes.back();
                    pendingNodes.pop_back();

                    levelValues.push_back(currentNode->val);

                    if (currentNode->right != nullptr) {
                        pendingNodes.push_front(currentNode->right);
                    }

                    if (currentNode->left != nullptr) {
                        pendingNodes.push_front(currentNode->left);
                    }
                }
            }

            zigzagTraversal.push_back(levelValues);
            leftToRight = !leftToRight;
        }

        return zigzagTraversal;
    }
};