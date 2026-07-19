class Solution {
public:
    // O(n) | O(h)
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        stack<pair<TreeNode*, TreeNode*>> st;

        st.push({root->left, root->right});

        while (!st.empty()) {
            auto [a, b] = st.top();
            st.pop();

            if (!a && !b)
                continue;

            if (!a || !b)
                return false;

            if (a->val != b->val)
                return false;

            st.push({a->left, b->right});
            st.push({a->right, b->left});
        }

        return true;
    }
};