// Approach 7: Zigzag traversal using two stacks

class Solution {
public:
    // O(n) | O(w)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagTraversal;

        if (root == nullptr) {
            return zigzagTraversal;
        }

        stack<TreeNode*> currentLevelNodes;
        stack<TreeNode*> nextLevelNodes;

        currentLevelNodes.push(root);

        bool leftToRight = true;
        vector<int> levelValues;

        while (!currentLevelNodes.empty()) {
            TreeNode* currentNode = currentLevelNodes.top();
            currentLevelNodes.pop();

            levelValues.push_back(currentNode->val);

            if (leftToRight) {
                if (currentNode->left != nullptr) {
                    nextLevelNodes.push(currentNode->left);
                }

                if (currentNode->right != nullptr) {
                    nextLevelNodes.push(currentNode->right);
                }
            } else {
                if (currentNode->right != nullptr) {
                    nextLevelNodes.push(currentNode->right);
                }

                if (currentNode->left != nullptr) {
                    nextLevelNodes.push(currentNode->left);
                }
            }

            if (currentLevelNodes.empty()) {
                zigzagTraversal.push_back(levelValues);
                levelValues.clear();

                swap(
                    currentLevelNodes,
                    nextLevelNodes
                );

                leftToRight = !leftToRight;
            }
        }

        return zigzagTraversal;
    }
};