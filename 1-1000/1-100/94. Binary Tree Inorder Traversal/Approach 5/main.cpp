class Solution {
public:
    // O(n) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<pair<int, TreeNode*>> st;

        if (root)
            st.push({0, root});

        while (!st.empty()) {
            auto [color, node] = st.top();
            st.pop();

            if (!node)
                continue;

            if (color == 1) {
                ans.push_back(node->val);
            } else {
                if (node->right)
                    st.push({0, node->right});

                st.push({1, node});

                if (node->left)
                    st.push({0, node->left});
            }
        }

        return ans;
    }
};