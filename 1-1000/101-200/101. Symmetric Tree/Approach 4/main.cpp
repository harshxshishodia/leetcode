class Solution {
public:
    void preorder(TreeNode* root, vector<string>& v) {
        if (!root) {
            v.push_back("#");
            return;
        }

        v.push_back(to_string(root->val));

        preorder(root->left, v);
        preorder(root->right, v);
    }

    void mirror(TreeNode* root, vector<string>& v) {
        if (!root) {
            v.push_back("#");
            return;
        }

        v.push_back(to_string(root->val));

        mirror(root->right, v);
        mirror(root->left, v);
    }
    
    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        vector<string> leftTree;
        vector<string> rightTree;

        preorder(root->left, leftTree);
        mirror(root->right, rightTree);

        return leftTree == rightTree;
    }
};