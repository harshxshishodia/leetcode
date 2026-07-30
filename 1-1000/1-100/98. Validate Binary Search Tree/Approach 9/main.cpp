// Approach 9: Iterative inorder traversal using a stack

class Solution {
public:
    // O(n) | O(h)
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> unfinishedNodes;

        TreeNode* currentNode = root;

        long long previousValue = 0;
        bool previousValueExists = false;

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
                previousValueExists &&
                currentNode->val <= previousValue
            ) {
                return false;
            }

            previousValue = currentNode->val;
            previousValueExists = true;

            currentNode = currentNode->right;
        }

        return true;
    }
};