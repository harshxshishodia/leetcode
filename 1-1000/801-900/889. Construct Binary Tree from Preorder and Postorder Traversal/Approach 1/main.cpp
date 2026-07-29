// Approach 1: Recursive divide and conquer with linear boundary search

class Solution {
private:
    TreeNode* buildTree(
        vector<int>& preorder,
        int preorderStart,
        int preorderEnd,
        vector<int>& postorder,
        int postorderStart,
        int postorderEnd
    ) {
        if (preorderStart > preorderEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preorderStart]);

        if (preorderStart == preorderEnd) {
            return root;
        }

        int leftSubtreeRootValue = preorder[preorderStart + 1];
        int leftSubtreeRootIndex = postorderStart;

        while (postorder[leftSubtreeRootIndex] != leftSubtreeRootValue) {
            leftSubtreeRootIndex++;
        }

        int leftSubtreeSize = leftSubtreeRootIndex - postorderStart + 1;

        root->left = buildTree(
            preorder,
            preorderStart + 1,
            preorderStart + leftSubtreeSize,
            postorder,
            postorderStart,
            leftSubtreeRootIndex
        );

        root->right = buildTree(
            preorder,
            preorderStart + leftSubtreeSize + 1,
            preorderEnd,
            postorder,
            leftSubtreeRootIndex + 1,
            postorderEnd - 1
        );

        return root;
    }

public:
    // O(n^2) | O(h)
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int numberOfNodes = preorder.size();

        return buildTree(
            preorder,
            0,
            numberOfNodes - 1,
            postorder,
            0,
            numberOfNodes - 1
        );
    }
};