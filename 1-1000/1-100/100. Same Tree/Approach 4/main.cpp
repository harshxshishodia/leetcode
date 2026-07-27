// Approach 4: Recursive preorder serialization

class Solution {
private:
    void serializeTree(TreeNode* node, vector<string>& serializedTree) {
        if (node == nullptr) {
            serializedTree.push_back("#");
            return;
        }

        serializedTree.push_back(to_string(node->val));

        serializeTree(node->left, serializedTree);
        serializeTree(node->right, serializedTree);
    }

public:
    // O(n) | O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> firstSerializedTree;
        vector<string> secondSerializedTree;

        serializeTree(p, firstSerializedTree);
        serializeTree(q, secondSerializedTree);

        return firstSerializedTree == secondSerializedTree;
    }
};