// Approach 3: Iterative DFS with node depths

class Solution {
private:
    struct NodeState {
        TreeNode* currentNode;
        int currentDepth;
    };

public:
    // O(n) | O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;

        if (root == nullptr) {
            return zigzagTraversal;
        }

        stack<NodeState> unfinishedNodes;
        unfinishedNodes.push({root, 0});

        while (!unfinishedNodes.empty()) {
            NodeState currentState = unfinishedNodes.top();
            unfinishedNodes.pop();

            TreeNode* currentNode = currentState.currentNode;
            int currentDepth = currentState.currentDepth;

            if (currentDepth == zigzagTraversal.size()) {
                zigzagTraversal.push_back({});
            }

            zigzagTraversal[currentDepth].push_back(currentNode->val);

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

        for (int level = 1; level < zigzagTraversal.size(); level += 2) {
            reverse(
                zigzagTraversal[level].begin(),
                zigzagTraversal[level].end()
            );
        }

        return zigzagTraversal;
    }
};