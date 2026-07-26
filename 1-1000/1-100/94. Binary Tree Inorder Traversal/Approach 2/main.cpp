// Approach 2: Recursive DFS with helper function

class Solution {
private:
    void inorder(TreeNode* node, vector<int>& traversal) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left, traversal);
        traversal.push_back(node->val);
        inorder(node->right, traversal);
    }

public:
    // O(n) | O(h)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);
        return traversal;
    }
};