class Solution {
public:
    // O(n) | O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qu;
        qu.push({p, q});

        while (!qu.empty()) {
            auto [a, b] = qu.front();
            qu.pop();

            if (a == nullptr && b == nullptr)
                continue;

            if (a == nullptr || b == nullptr)
                return false;

            if (a->val != b->val)
                return false;

            qu.push({a->left, b->left});
            qu.push({a->right, b->right});
        }

        return true;
    }
};