// Approach 6: Iterative inorder traversal using a stack

class Solution {
public:
    // O(n) | O(h)
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> unfinishedNodes;

        TreeNode* currentNode = root;
        TreeNode* previousNode = nullptr;
        TreeNode* firstSwappedNode = nullptr;
        TreeNode* secondSwappedNode = nullptr;

        while (
            currentNode != nullptr ||
            !unfinishedNodes.empty()
        ) {
            while (currentNode != nullptr) {
                unfinishedNodes.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = unfinishedNodes.top();
            unfinishedNodes.pop();

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

        swap(
            firstSwappedNode->val,
            secondSwappedNode->val
        );
    }
};