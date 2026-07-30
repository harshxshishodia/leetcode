// Approach 2: Recursive DFS with depth grouping and level reversal

class Solution {
private:
    void traverseTree(
        TreeNode* currentNode,
        int currentDepth,
        vector<vector<int>>& zigzagTraversal
    ) {
        if (currentNode == nullptr) {
            return;
        }

        if (currentDepth == zigzagTraversal.size()) {
            zigzagTraversal.push_back({});
        }

        zigzagTraversal[currentDepth].push_back(currentNode->val);

        traverseTree(
            currentNode->left,
            currentDepth + 1,
            zigzagTraversal
        );

        traverseTree(
            currentNode->right,
            currentDepth + 1,
            zigzagTraversal
        );
    }

public:
    // O(n) | O(h)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;

        traverseTree(
            root,
            0,
            zigzagTraversal
        );

        for (int level = 1; level < zigzagTraversal.size(); level += 2) {
            reverse(
                zigzagTraversal[level].begin(),
                zigzagTraversal[level].end()
            );
        }

        return zigzagTraversal;
    }
};