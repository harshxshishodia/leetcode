class Solution {
public:
    // O(n) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (!root)
            return ans;

        stack<pair<TreeNode*, bool>> st;
        st.push({root, false});

        while (!st.empty()) {
            auto [node, visited] = st.top();
            st.pop();

            if (!node)
                continue;

            if (visited) {
                ans.push_back(node->val);
            } else {
                st.push({node->right, false});
                st.push({node, true});
                st.push({node->left, false});
            }
        }

        return ans;
    }
};