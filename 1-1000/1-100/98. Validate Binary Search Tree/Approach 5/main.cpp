// Approach 5: Recursive validation using lower and upper bounds

class Solution {
private:
    bool validateTree(
        TreeNode* currentNode,
        long long lowerBound,
        long long upperBound
    ) {
        if (currentNode == nullptr) {
            return true;
        }

        if (
            currentNode->val <= lowerBound ||
            currentNode->val >= upperBound
        ) {
            return false;
        }

        return (
            validateTree(
                currentNode->left,
                lowerBound,
                currentNode->val
            ) &&
            validateTree(
                currentNode->right,
                currentNode->val,
                upperBound
            )
        );
    }

public:
    // O(n) | O(h)
    bool isValidBST(TreeNode* root) {
        return validateTree(
            root,
            LLONG_MIN,
            LLONG_MAX
        );
    }
};