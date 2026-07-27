// Approach 6: Level-order serialization

class Solution {
private:
    vector<string> serializeTree(TreeNode* root) {
        vector<string> serializedTree;
        queue<TreeNode*> nodes;

        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* currentNode = nodes.front();
            nodes.pop();

            if (currentNode == nullptr) {
                serializedTree.push_back("#");
                continue;
            }

            serializedTree.push_back(
                to_string(currentNode->val)
            );

            nodes.push(currentNode->left);
            nodes.push(currentNode->right);
        }

        return serializedTree;
    }

public:
    // O(n) | O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> firstSerializedTree = serializeTree(p);
        vector<string> secondSerializedTree = serializeTree(q);

        return firstSerializedTree == secondSerializedTree;
    }
};