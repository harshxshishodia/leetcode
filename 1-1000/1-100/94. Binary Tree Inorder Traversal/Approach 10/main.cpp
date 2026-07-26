// Approach 10: Morris inorder traversal

class Solution {
public:
    // O(n) | O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        TreeNode* currentNode = root;

        while (currentNode != nullptr) {
            if (currentNode->left == nullptr) {
                traversal.push_back(currentNode->val);
                currentNode = currentNode->right;
            } else {
                TreeNode* predecessor = currentNode->left;

                while (
                    predecessor->right != nullptr &&
                    predecessor->right != currentNode
                ) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = currentNode;
                    currentNode = currentNode->left;
                } else {
                    predecessor->right = nullptr;
                    traversal.push_back(currentNode->val);
                    currentNode = currentNode->right;
                }
            }
        }

        return traversal;
    }
};