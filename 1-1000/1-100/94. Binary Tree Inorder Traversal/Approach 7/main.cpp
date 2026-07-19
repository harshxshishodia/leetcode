class Solution {
public:
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    // O(n) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);

        vector<int> ans;

        for (TreeNode* node : nodes)
            ans.push_back(node->val);

        return ans;
    }
};