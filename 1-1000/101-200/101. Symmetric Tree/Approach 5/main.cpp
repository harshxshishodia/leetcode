// Approach 5: Recursive mirrored serialization

class Solution {
private:
    void serializeNormally(TreeNode* node, vector<string>& serialization) {
        if (node == nullptr) {
            serialization.push_back("#");
            return;
        }

        serialization.push_back(to_string(node->val));

        serializeNormally(node->left, serialization);
        serializeNormally(node->right, serialization);
    }

    void serializeAsMirror(TreeNode* node, vector<string>& serialization) {
        if (node == nullptr) {
            serialization.push_back("#");
            return;
        }

        serialization.push_back(to_string(node->val));

        serializeAsMirror(node->right, serialization);
        serializeAsMirror(node->left, serialization);
    }

public:
    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        vector<string> leftSerialization;
        vector<string> rightMirrorSerialization;

        serializeNormally(root->left, leftSerialization);
        serializeAsMirror(root->right, rightMirrorSerialization);

        return leftSerialization == rightMirrorSerialization;
    }
};