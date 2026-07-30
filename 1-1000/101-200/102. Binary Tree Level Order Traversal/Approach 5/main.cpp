// Approach 5: BFS using node and depth pairs

class Solution {
private:
    struct NodeState {
        TreeNode* currentNode;
        int currentDepth;
    };

public:
    // O(n) | O(w)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        if (root == nullptr) {
            return levelOrderTraversal;
        }

        queue<NodeState> pendingNodes;
        pendingNodes.push({root, 0});

        while (!pendingNodes.empty()) {
            NodeState currentState = pendingNodes.front();
            pendingNodes.pop();

            TreeNode* currentNode = currentState.currentNode;
            int currentDepth = currentState.currentDepth;

            if (currentDepth == levelOrderTraversal.size()) {
                levelOrderTraversal.push_back({});
            }

            levelOrderTraversal[currentDepth].push_back(
                currentNode->val
            );

            if (currentNode->left != nullptr) {
                pendingNodes.push({
                    currentNode->left,
                    currentDepth + 1
                });
            }

            if (currentNode->right != nullptr) {
                pendingNodes.push({
                    currentNode->right,
                    currentDepth + 1
                });
            }
        }

        return levelOrderTraversal;
    }
};