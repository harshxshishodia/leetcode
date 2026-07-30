// Approach 8: Recursive inorder traversal with previous value

class Solution {
private:
    long long previousValue;
    bool previousValueExists = false;

    bool validateInorder(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return true;
        }

        if (!validateInorder(currentNode->left)) {
            return false;
        }

        if (
            previousValueExists &&
            currentNode->val <= previousValue
        ) {
            return false;
        }

        previousValue = currentNode->val;
        previousValueExists = true;

        return validateInorder(currentNode->right);
    }

public:
    // O(n) | O(h)
    bool isValidBST(TreeNode* root) {
        previousValueExists = false;

        return validateInorder(root);
    }
};