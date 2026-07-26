// Approach 4: Iterative DFS using explicit stack

class Solution {
public:
    // O(n) | O(h)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> pendingNodes;

        TreeNode* currentNode = root;

        while (currentNode != nullptr || !pendingNodes.empty()) {
            while (currentNode != nullptr) {
                pendingNodes.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = pendingNodes.top();
            pendingNodes.pop();

            traversal.push_back(currentNode->val);
            currentNode = currentNode->right;
        }

        return traversal;
    }
};