// Approach 1: Check only the immediate children
// Incorrect naive approach

class Solution {
private:
    bool validateTree(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return true;
        }

        if (
            currentNode->left != nullptr &&
            currentNode->left->val >= currentNode->val
        ) {
            return false;
        }

        if (
            currentNode->right != nullptr &&
            currentNode->right->val <= currentNode->val
        ) {
            return false;
        }

        return (
            validateTree(currentNode->left) &&
            validateTree(currentNode->right)
        );
    }

public:
    // O(n) | O(h), but logically incorrect
    bool isValidBST(TreeNode* root) {
        return validateTree(root);
    }
};