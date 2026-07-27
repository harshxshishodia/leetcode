// Approach 6: Construct the mirror and compare both trees

class Solution {
private:
    TreeNode* createMirror(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        TreeNode* mirroredNode = new TreeNode(node->val);

        mirroredNode->left = createMirror(node->right);
        mirroredNode->right = createMirror(node->left);

        return mirroredNode;
    }

    bool areSameTrees(TreeNode* firstNode, TreeNode* secondNode) {
        if (firstNode == nullptr && secondNode == nullptr) {
            return true;
        }

        if (firstNode == nullptr || secondNode == nullptr) {
            return false;
        }

        if (firstNode->val != secondNode->val) {
            return false;
        }

        return areSameTrees(firstNode->left, secondNode->left) && areSameTrees(firstNode->right, secondNode->right);
    }

    void deleteTree(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }

public:
    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        TreeNode* mirroredRightSubtree = createMirror(root->right);

        bool symmetric = areSameTrees(root->left, mirroredRightSubtree);

        deleteTree(mirroredRightSubtree);

        return symmetric;
    }
};