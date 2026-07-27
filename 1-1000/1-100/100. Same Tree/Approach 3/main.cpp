// Approach 3: Iterative BFS using a queue

class Solution {
public:
    // O(n) | O(w)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> nodePairs;

        nodePairs.push({p, q});

        while (!nodePairs.empty()) {
            TreeNode* firstNode = nodePairs.front().first;
            TreeNode* secondNode = nodePairs.front().second;

            nodePairs.pop();

            if (firstNode == nullptr && secondNode == nullptr) {
                continue;
            }

            if (firstNode == nullptr || secondNode == nullptr) {
                return false;
            }

            if (firstNode->val != secondNode->val) {
                return false;
            }

            nodePairs.push({firstNode->left,secondNode->left});

            nodePairs.push({firstNode->right,secondNode->right});
        }

        return true;
    }
};