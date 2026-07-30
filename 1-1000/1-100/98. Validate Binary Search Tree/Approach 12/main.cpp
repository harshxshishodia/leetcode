// Approach 12: Morris inorder traversal

class Solution {
public:
    // O(n) | O(1)
    bool isValidBST(TreeNode* root) {
        TreeNode* currentNode = root;

        long long previousValue = 0;
        bool previousValueExists = false;
        bool treeIsValid = true;

        while (currentNode != nullptr) {
            if (currentNode->left == nullptr) {
                if (
                    previousValueExists &&
                    currentNode->val <= previousValue
                ) {
                    treeIsValid = false;
                }

                previousValue = currentNode->val;
                previousValueExists = true;

                currentNode = currentNode->right;
            } else {
                TreeNode* inorderPredecessor = currentNode->left;

                while (
                    inorderPredecessor->right != nullptr &&
                    inorderPredecessor->right != currentNode
                ) {
                    inorderPredecessor = inorderPredecessor->right;
                }

                if (inorderPredecessor->right == nullptr) {
                    inorderPredecessor->right = currentNode;
                    currentNode = currentNode->left;
                } else {
                    inorderPredecessor->right = nullptr;

                    if (
                        previousValueExists &&
                        currentNode->val <= previousValue
                    ) {
                        treeIsValid = false;
                    }

                    previousValue = currentNode->val;
                    previousValueExists = true;

                    currentNode = currentNode->right;
                }
            }
        }

        return treeIsValid;
    }
};