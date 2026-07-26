// Approach 8: Iterative DFS using an expanded-node set

class Solution {
public:
    // O(n) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        if (root == nullptr) {
            return traversal;
        }

        stack<TreeNode*> traversalStack;
        unordered_set<TreeNode*> expandedNodes;

        traversalStack.push(root);

        while (!traversalStack.empty()) {
            TreeNode* currentNode = traversalStack.top();

            if (
                currentNode->left != nullptr &&
                expandedNodes.find(currentNode) == expandedNodes.end()
            ) {
                expandedNodes.insert(currentNode);
                traversalStack.push(currentNode->left);
            } else {
                traversalStack.pop();
                traversal.push_back(currentNode->val);

                if (currentNode->right != nullptr) {
                    traversalStack.push(currentNode->right);
                }
            }
        }

        return traversal;
    }
};