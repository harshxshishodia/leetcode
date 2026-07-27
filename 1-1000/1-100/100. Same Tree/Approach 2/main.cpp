// Approach 2: Iterative DFS using a stack

class Solution {
public:
    // O(n) | O(h)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> nodePairs;

        nodePairs.push({p, q});

        while (!nodePairs.empty()) {
            TreeNode* firstNode = nodePairs.top().first;
            TreeNode* secondNode = nodePairs.top().second;

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

            nodePairs.push({firstNode->right,secondNode->right});

            nodePairs.push({firstNode->left,secondNode->left});
        }

        return true;
    }
};