// Approach 1: Recursive DFS comparison

class Solution {
public:
    // O(n) | O(h)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        bool leftSubtreesAreSame = isSameTree(p->left, q->left);
        bool rightSubtreesAreSame = isSameTree(p->right, q->right);

        return leftSubtreesAreSame && rightSubtreesAreSame;
    }
};