// Approach 2: Divide and conquer with postorder index map

class Solution {
private:
    unordered_map<int, int> postorderIndex;

    TreeNode* buildTree(
        vector<int>& preorder,
        int preorderStart,
        int preorderEnd,
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
        int leftSubtreeRootIndex = postorderIndex[leftSubtreeRootValue];
        int leftSubtreeSize = leftSubtreeRootIndex - postorderStart + 1;

        root->left = buildTree(
            preorder,
            preorderStart + 1,
            preorderStart + leftSubtreeSize,
            postorderStart,
            leftSubtreeRootIndex
        );

        root->right = buildTree(
            preorder,
            preorderStart + leftSubtreeSize + 1,
            preorderEnd,
            leftSubtreeRootIndex + 1,
            postorderEnd - 1
        );

        return root;
    }

public:
    // O(n) | O(n)
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int numberOfNodes = postorder.size();

        for (int index = 0; index < numberOfNodes; index++) {
            postorderIndex[postorder[index]] = index;
        }

        return buildTree(
            preorder,
            0,
            numberOfNodes - 1,
            0,
            numberOfNodes - 1
        );
    }
};