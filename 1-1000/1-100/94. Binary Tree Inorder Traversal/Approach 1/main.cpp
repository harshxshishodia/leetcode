// Approach 1: Recursive vector merging

class Solution {
public:
    // O(n^2) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> leftTraversal = inorderTraversal(root->left);
        vector<int> rightTraversal = inorderTraversal(root->right);
        vector<int> traversal;

        traversal.insert(
            traversal.end(),
            leftTraversal.begin(),
            leftTraversal.end()
        );

        traversal.push_back(root->val);

        traversal.insert(
            traversal.end(),
            rightTraversal.begin(),
            rightTraversal.end()
        );

        return traversal;
    }
};