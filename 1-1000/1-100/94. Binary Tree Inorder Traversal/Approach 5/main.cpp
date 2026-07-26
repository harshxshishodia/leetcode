// Approach 5: Iterative DFS using node states

class Solution {
public:
    // O(n) | O(h)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        if (root == nullptr) {
            return traversal;
        }

        stack<pair<TreeNode*, bool>> traversalStack;
        traversalStack.push({root, false});

        while (!traversalStack.empty()) {
            auto [currentNode, shouldProcess] = traversalStack.top();
            traversalStack.pop();

            if (currentNode == nullptr) {
                continue;
            }

            if (shouldProcess) {
                traversal.push_back(currentNode->val);
            } else {
                traversalStack.push({currentNode->right, false});
                traversalStack.push({currentNode, true});
                traversalStack.push({currentNode->left, false});
            }
        }

        return traversal;
    }
};