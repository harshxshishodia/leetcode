// Approach 3: Recursive DFS using lambda function

class Solution {
public:
    // O(n) | O(h)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (node == nullptr) {
                return;
            }

            inorder(node->left);
            traversal.push_back(node->val);
            inorder(node->right);
        };

        inorder(root);

        return traversal;
    }
};