// Approach 2: Recursive DFS with the depth of every node

class Solution {
private:
    void traverseTree(
        TreeNode* currentNode,
        int currentDepth,
        vector<vector<int>>& levelOrderTraversal
    ) {
        if (currentNode == nullptr) {
            return;
        }

        if (currentDepth == levelOrderTraversal.size()) {
            levelOrderTraversal.push_back({});
        }

        levelOrderTraversal[currentDepth].push_back(
            currentNode->val
        );

        traverseTree(
            currentNode->left,
            currentDepth + 1,
            levelOrderTraversal
        );

        traverseTree(
            currentNode->right,
            currentDepth + 1,
            levelOrderTraversal
        );
    }

public:
    // O(n) | O(h)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        traverseTree(
            root,
            0,
            levelOrderTraversal
        );

        return levelOrderTraversal;
    }
};