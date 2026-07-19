class Solution {
public:
    // O(n) | O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {
            auto [a, b] = st.top();
            st.pop();

            if (a == nullptr && b == nullptr)
                continue;

            if (a == nullptr || b == nullptr)
                return false;

            if (a->val != b->val)
                return false;

            st.push({a->right, b->right});
            st.push({a->left, b->left});
        }

        return true;
    }
};