// Approach 3: Iterative DFS using a stack and node depths

class Solution {
private:
    struct NodeState {
        TreeNode* currentNode;
        int currentDepth;
    };

public:
    // O(n) | O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        if (root == nullptr) {
            return levelOrderTraversal;
        }

        stack<NodeState> unfinishedNodes;
        unfinishedNodes.push({root, 0});

        while (!unfinishedNodes.empty()) {
            NodeState currentState = unfinishedNodes.top();
            unfinishedNodes.pop();

            TreeNode* currentNode = currentState.currentNode;
            int currentDepth = currentState.currentDepth;

            if (currentDepth == levelOrderTraversal.size()) {
                levelOrderTraversal.push_back({});
            }

            levelOrderTraversal[currentDepth].push_back(
                currentNode->val
            );

            if (currentNode->right != nullptr) {
                unfinishedNodes.push({
                    currentNode->right,
                    currentDepth + 1
                });
            }

            if (currentNode->left != nullptr) {
                unfinishedNodes.push({
                    currentNode->left,
                    currentDepth + 1
                });
            }
        }

        return levelOrderTraversal;
    }
};