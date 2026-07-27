// Approach 1: Generate all permutations and remove duplicate BSTs

class Solution {
private:
    TreeNode* insertNode(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->val) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }

        return root;
    }

    string serializeTree(TreeNode* root) {
        if (root == nullptr) {
            return "#,";
        }

        return to_string(root->val) + "," + serializeTree(root->left) + serializeTree(root->right);
    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

public:
    // O(n! * n^2) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<int> values(n);

        for (int index = 0; index < n; index++) {
            values[index] = index + 1;
        }

        unordered_set<string> generatedTrees;
        vector<TreeNode*> uniqueTrees;

        do {
            TreeNode* root = nullptr;

            for (int value : values) {
                root = insertNode(root, value);
            }

            string serializedTree = serializeTree(root);

            if (generatedTrees.insert(serializedTree).second) {
                uniqueTrees.push_back(root);
            } else {
                deleteTree(root);
            }
        } while (next_permutation(values.begin(), values.end()));

        return uniqueTrees;
    }
};