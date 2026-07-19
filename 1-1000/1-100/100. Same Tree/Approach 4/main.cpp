class Solution {
public:
    // O(n) | O(n)
    void serialize(TreeNode* root, vector<int>& tree) {
        if (root == nullptr) {
            tree.push_back(INT_MIN);
            return;
        }

        tree.push_back(root->val);

        serialize(root->left, tree);
        serialize(root->right, tree);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> first;
        vector<int> second;

        serialize(p, first);
        serialize(q, second);

        return first == second;
    }
};