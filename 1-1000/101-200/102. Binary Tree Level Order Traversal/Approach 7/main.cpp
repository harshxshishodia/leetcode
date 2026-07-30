// Approach 7: Level-by-level traversal using vectors of nodes

class Solution {
public:
    // O(n) | O(w)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        if (root == nullptr) {
            return levelOrderTraversal;
        }

        vector<TreeNode*> currentLevelNodes;
        currentLevelNodes.push_back(root);

        while (!currentLevelNodes.empty()) {
            vector<int> levelValues;
            vector<TreeNode*> nextLevelNodes;

            for (TreeNode* currentNode : currentLevelNodes) {
                levelValues.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    nextLevelNodes.push_back(
                        currentNode->left
                    );
                }

                if (currentNode->right != nullptr) {
                    nextLevelNodes.push_back(
                        currentNode->right
                    );
                }
            }

            levelOrderTraversal.push_back(levelValues);
            currentLevelNodes = move(nextLevelNodes);
        }

        return levelOrderTraversal;
    }
};