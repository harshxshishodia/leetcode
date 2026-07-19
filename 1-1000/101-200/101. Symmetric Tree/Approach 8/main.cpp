class Solution {
public:
    string hash(TreeNode* root) {
        if (!root)
            return "#";

        return "(" + to_string(root->val) + hash(root->left) + hash(root->right) + ")";
    }

    string mirrorHash(TreeNode* root) {
        if (!root)
            return "#";

        return "(" + to_string(root->val) + mirrorHash(root->right) + mirrorHash(root->left) +")";
    }
    

    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return hash(root->left) == mirrorHash(root->right);
    }
};