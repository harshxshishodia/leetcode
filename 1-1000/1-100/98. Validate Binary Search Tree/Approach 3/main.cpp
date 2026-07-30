// Approach 3: Repeatedly find subtree minimum and maximum

class Solution {
private:
    long long findMinimumValue(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return LLONG_MAX;
        }

        long long leftMinimum = findMinimumValue(currentNode->left);
        long long rightMinimum = findMinimumValue(currentNode->right);

        return min(
            (long long)currentNode->val,
            min(leftMinimum, rightMinimum)
        );
    }

    long long findMaximumValue(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return LLONG_MIN;
        }

        long long leftMaximum = findMaximumValue(currentNode->left);
        long long rightMaximum = findMaximumValue(currentNode->right);

        return max(
            (long long)currentNode->val,
            max(leftMaximum, rightMaximum)
        );
    }

    bool validateTree(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return true;
        }

        if (
            currentNode->left != nullptr &&
            findMaximumValue(currentNode->left) >= currentNode->val
        ) {
            return false;
        }

        if (
            currentNode->right != nullptr &&
            findMinimumValue(currentNode->right) <= currentNode->val
        ) {
            return false;
        }

        return (
            validateTree(currentNode->left) &&
            validateTree(currentNode->right)
        );
    }

public:
    // O(n^2) | O(h)
    bool isValidBST(TreeNode* root) {
        return validateTree(root);
    }
};