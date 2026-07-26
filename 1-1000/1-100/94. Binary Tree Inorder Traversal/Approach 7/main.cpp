// Approach 7: Iterative DFS using null markers

class Solution {
public:
    // O(n) | O(h)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        if (root == nullptr) {
            return traversal;
        }

        stack<TreeNode*> traversalStack;
        traversalStack.push(root);

        while (!traversalStack.empty()) {
            TreeNode* currentNode = traversalStack.top();
            traversalStack.pop();

            if (currentNode != nullptr) {
                if (currentNode->right != nullptr) {
                    traversalStack.push(currentNode->right);
                }

                traversalStack.push(currentNode);
                traversalStack.push(nullptr);

                if (currentNode->left != nullptr) {
                    traversalStack.push(currentNode->left);
                }
            } else {
                currentNode = traversalStack.top();
                traversalStack.pop();

                traversal.push_back(currentNode->val);
            }
        }

        return traversal;
    }
};