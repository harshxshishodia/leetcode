// Approach 3: Iterative DFS using a stack

class Solution {
public:
    // O(n) | O(h)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        stack<pair<TreeNode*, TreeNode*>> nodePairs;

        nodePairs.push({root->left, root->right});

        while (!nodePairs.empty()) {
            TreeNode* leftNode = nodePairs.top().first;
            TreeNode* rightNode = nodePairs.top().second;

            nodePairs.pop();

            if (leftNode == nullptr && rightNode == nullptr) {
                continue;
            }

            if (leftNode == nullptr || rightNode == nullptr) {
                return false;
            }

            if (leftNode->val != rightNode->val) {
                return false;
            }

            nodePairs.push({leftNode->left, rightNode->right});
            nodePairs.push({leftNode->right, rightNode->left});
        }

        return true;
    }
};