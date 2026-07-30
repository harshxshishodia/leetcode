// Approach 5: Recursive inorder traversal with previous node

class Solution {
private:
    TreeNode* previousNode = nullptr;
    TreeNode* firstSwappedNode = nullptr;
    TreeNode* secondSwappedNode = nullptr;

    void findSwappedNodes(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        findSwappedNodes(currentNode->left);

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

        findSwappedNodes(currentNode->right);
    }

public:
    // O(n) | O(h)
    void recoverTree(TreeNode* root) {
        findSwappedNodes(root);

        swap(
            firstSwappedNode->val,
            secondSwappedNode->val
        );
    }
};