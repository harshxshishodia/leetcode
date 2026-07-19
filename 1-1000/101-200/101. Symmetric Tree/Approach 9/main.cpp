class Solution {
public:
    void preorder(TreeNode* root, vector<int>& v) {
        if (!root) {
            v.push_back(INT_MIN);
            return;
        }

        v.push_back(root->val);

        preorder(root->left, v);
        preorder(root->right, v);
    }

    void mirror(TreeNode* root, vector<int>& v) {
        if (!root) {
            v.push_back(INT_MIN);
            return;
        }

        v.push_back(root->val);

        mirror(root->right, v);
        mirror(root->left, v);
    }
    
    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        vector<int> leftTree;
        vector<int> rightTree;

        preorder(root->left, leftTree);
        mirror(root->right, rightTree);

        return leftTree == rightTree;
    }
};