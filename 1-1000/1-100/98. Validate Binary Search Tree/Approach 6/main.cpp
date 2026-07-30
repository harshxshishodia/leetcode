// Approach 6: Iterative validation using bounds and a stack

class Solution {
private:
    struct NodeState {
        TreeNode* currentNode;
        long long lowerBound;
        long long upperBound;
    };

public:
    // O(n) | O(h)
    bool isValidBST(TreeNode* root) {
        stack<NodeState> unfinishedNodes;

        unfinishedNodes.push({
            root,
            LLONG_MIN,
            LLONG_MAX
        });

        while (!unfinishedNodes.empty()) {
            NodeState currentState = unfinishedNodes.top();
            unfinishedNodes.pop();

            TreeNode* currentNode = currentState.currentNode;

            if (currentNode == nullptr) {
                continue;
            }

            if (
                currentNode->val <= currentState.lowerBound ||
                currentNode->val >= currentState.upperBound
            ) {
                return false;
            }

            unfinishedNodes.push({
                currentNode->right,
                currentNode->val,
                currentState.upperBound
            });

            unfinishedNodes.push({
                currentNode->left,
                currentState.lowerBound,
                currentNode->val
            });
        }

        return true;
    }
};