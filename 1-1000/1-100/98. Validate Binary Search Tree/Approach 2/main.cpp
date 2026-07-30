// Approach 2: Check every node in the left and right subtrees

class Solution {
private:
    bool containsOnlySmallerValues(TreeNode* currentNode, long long parentValue) {
        if (currentNode == nullptr) {
            return true;
        }

        if (currentNode->val >= parentValue) {
            return false;
        }

        return (
            containsOnlySmallerValues(currentNode->left, parentValue) &&
            containsOnlySmallerValues(currentNode->right, parentValue)
        );
    }

    bool containsOnlyGreaterValues(TreeNode* currentNode, long long parentValue) {
        if (currentNode == nullptr) {
            return true;
        }

        if (currentNode->val <= parentValue) {
            return false;
        }

        return (
            containsOnlyGreaterValues(currentNode->left, parentValue) &&
            containsOnlyGreaterValues(currentNode->right, parentValue)
        );
    }

    bool validateTree(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return true;
        }

        if (
            !containsOnlySmallerValues(
                currentNode->left,
                currentNode->val
            )
        ) {
            return false;
        }

        if (
            !containsOnlyGreaterValues(
                currentNode->right,
                currentNode->val
            )
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