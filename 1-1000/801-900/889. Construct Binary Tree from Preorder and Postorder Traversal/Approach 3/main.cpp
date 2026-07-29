// Approach 3: Recursive synchronized preorder and postorder indices

class Solution {
private:
    int preorderIndex = 0;
    int postorderIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preorderIndex]);
        preorderIndex++;

        if (root->val != postorder[postorderIndex]) {
            root->left = buildTree(preorder, postorder);
        }

        if (root->val != postorder[postorderIndex]) {
            root->right = buildTree(preorder, postorder);
        }

        postorderIndex++;

        return root;
    }

public:
    // O(n) | O(h)
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildTree(preorder, postorder);
    }
};