// Approach 1: Recursive mirror comparison

class Solution {
private:
    bool areMirrors(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }

        if (leftNode == nullptr || rightNode == nullptr) {
            return false;
        }

        if (leftNode->val != rightNode->val) {
            return false;
        }

        bool outerSubtreesAreMirrors = areMirrors(leftNode->left, rightNode->right);
        bool innerSubtreesAreMirrors = areMirrors(leftNode->right, rightNode->left);

        return outerSubtreesAreMirrors && innerSubtreesAreMirrors;
    }

public:
    // O(n) | O(h)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return areMirrors(root->left, root->right);
    }
};