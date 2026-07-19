class Solution {
public:
    string hashTree(TreeNode* root) {
        if (root == nullptr)
            return "#";

        return "(" + to_string(root->val) + hashTree(root->left) + hashTree(root->right) + ")";
    }
    
    // O(n) | O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return hashTree(p) == hashTree(q);
    }
};