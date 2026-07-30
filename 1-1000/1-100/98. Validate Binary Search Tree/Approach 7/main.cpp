// Approach 7: Store the inorder traversal and check adjacent values

class Solution {
private:
    void createInorderTraversal(
        TreeNode* currentNode,
        vector<int>& inorderValues
    ) {
        if (currentNode == nullptr) {
            return;
        }

        createInorderTraversal(
            currentNode->left,
            inorderValues
        );

        inorderValues.push_back(currentNode->val);

        createInorderTraversal(
            currentNode->right,
            inorderValues
        );
    }

public:
    // O(n) | O(n)
    bool isValidBST(TreeNode* root) {
        vector<int> inorderValues;

        createInorderTraversal(
            root,
            inorderValues
        );

        for (
            int index = 1;
            index < inorderValues.size();
            index++
        ) {
            if (
                inorderValues[index] <=
                inorderValues[index - 1]
            ) {
                return false;
            }
        }

        return true;
    }
};