class Solution {
public:
    // O(n) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        stack<pair<string, TreeNode*>> st;

        if (root)
            st.push({"go", root});

        while (!st.empty()) {
            auto [cmd, node] = st.top();
            st.pop();

            if (cmd == "print") {
                ans.push_back(node->val);
            } else {
                if (node->right)
                    st.push({"go", node->right});

                st.push({"print", node});

                if (node->left)
                    st.push({"go", node->left});
            }
        }

        return ans;
    }
};