// Approach 7: Morris inorder traversal with constant extra space

class Solution {
public:
    // O(n) | O(1)
    void recoverTree(TreeNode* root) {
        TreeNode* currentNode = root;
        TreeNode* previousNode = nullptr;
        TreeNode* firstSwappedNode = nullptr;
        TreeNode* secondSwappedNode = nullptr;

        while (currentNode != nullptr) {
            if (currentNode->left == nullptr) {
                if (
                    previousNode != nullptr &&
                    previousNode->val > currentNode->val
                ) {
                    if (firstSwappedNode == nullptr) {
                        firstSwappedNode = previousNode;
                    }

                    secondSwappedNode = currentNode;
                }

                previousNode = currentNode;
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
                        previousNode != nullptr &&
                        previousNode->val > currentNode->val
                    ) {
                        if (firstSwappedNode == nullptr) {
                            firstSwappedNode = previousNode;
                        }

                        secondSwappedNode = currentNode;
                    }

                    previousNode = currentNode;
                    currentNode = currentNode->right;
                }
            }
        }

        swap(
            firstSwappedNode->val,
            secondSwappedNode->val
        );
    }
};