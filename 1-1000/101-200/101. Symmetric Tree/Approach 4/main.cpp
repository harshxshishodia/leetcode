// Approach 4: Level-order traversal with palindrome checking

class Solution {
private:
    bool isMirrorLevel(const vector<TreeNode*>& currentLevel) {
        int leftIndex = 0;
        int rightIndex = currentLevel.size() - 1;

        while (leftIndex < rightIndex) {
            TreeNode* leftNode = currentLevel[leftIndex];
            TreeNode* rightNode = currentLevel[rightIndex];

            if (leftNode == nullptr && rightNode == nullptr) {
                leftIndex++;
                rightIndex--;
                continue;
            }

            if (leftNode == nullptr || rightNode == nullptr) {
                return false;
            }

            if (leftNode->val != rightNode->val) {
                return false;
            }

            leftIndex++;
            rightIndex--;
        }

        return true;
    }

public:
    // O(n) | O(w)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> nodes;

        nodes.push(root);

        while (!nodes.empty()) {
            int levelSize = nodes.size();
            vector<TreeNode*> currentLevel;

            for (int index = 0; index < levelSize; index++) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();

                currentLevel.push_back(currentNode);

                if (currentNode == nullptr) {
                    continue;
                }

                nodes.push(currentNode->left);
                nodes.push(currentNode->right);
            }

            if (!isMirrorLevel(currentLevel)) {
                return false;
            }
        }

        return true;
    }
};