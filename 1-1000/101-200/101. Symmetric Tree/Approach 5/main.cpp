class Solution {
public:
    // O(n) | O(n)
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<long long> level;

            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();

                if (!cur) {
                    level.push_back(LLONG_MIN);
                    continue;
                }

                level.push_back(cur->val);

                q.push(cur->left);
                q.push(cur->right);
            }

            int i = 0;
            int j = level.size() - 1;

            while (i < j) {
                if (level[i] != level[j])
                    return false;

                i++;
                j--;
            }
        }

        return true;
    }
};