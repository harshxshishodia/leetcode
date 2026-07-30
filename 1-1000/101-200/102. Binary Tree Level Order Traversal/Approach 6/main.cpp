// Approach 6: BFS using two separate queues

class Solution {
public:
    // O(n) | O(w)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderTraversal;

        if (root == nullptr) {
            return levelOrderTraversal;
        }

        queue<TreeNode*> currentLevelNodes;
        queue<TreeNode*> nextLevelNodes;

        currentLevelNodes.push(root);

        while (!currentLevelNodes.empty()) {
            vector<int> levelValues;

            while (!currentLevelNodes.empty()) {
                TreeNode* currentNode = currentLevelNodes.front();
                currentLevelNodes.pop();

                levelValues.push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    nextLevelNodes.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    nextLevelNodes.push(currentNode->right);
                }
            }

            levelOrderTraversal.push_back(levelValues);

            swap(
                currentLevelNodes,
                nextLevelNodes
            );
        }

        return levelOrderTraversal;
    }
};