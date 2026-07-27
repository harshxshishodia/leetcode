// Approach 2: Iterative BFS using a queue

class Solution {
public:
    // O(n) | O(w)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<pair<TreeNode*, TreeNode*>> nodePairs;

        nodePairs.push({root->left, root->right});

        while (!nodePairs.empty()) {
            TreeNode* leftNode = nodePairs.front().first;
            TreeNode* rightNode = nodePairs.front().second;

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