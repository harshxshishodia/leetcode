// Approach 2: Backtracking over all insertion orders

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

    void generateInsertionOrders(
        int n,
        vector<bool>& usedValues,
        vector<int>& insertionOrder,
        unordered_set<string>& generatedTrees,
        vector<TreeNode*>& uniqueTrees
    ) {
        if (insertionOrder.size() == n) {
            TreeNode* root = nullptr;

            for (int value : insertionOrder) {
                root = insertNode(root, value);
            }

            string serializedTree = serializeTree(root);

            if (generatedTrees.insert(serializedTree).second) {
                uniqueTrees.push_back(root);
            } else {
                deleteTree(root);
            }

            return;
        }

        for (int value = 1; value <= n; value++) {
            if (usedValues[value]) {
                continue;
            }

            usedValues[value] = true;
            insertionOrder.push_back(value);

            generateInsertionOrders(n,usedValues,insertionOrder,generatedTrees,uniqueTrees);

            insertionOrder.pop_back();
            usedValues[value] = false;
        }
    }

public:
    // O(n! * n^2) | O(n * Cn + n)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<bool> usedValues(n + 1, false);
        vector<int> insertionOrder;
        unordered_set<string> generatedTrees;
        vector<TreeNode*> uniqueTrees;

        generateInsertionOrders(n,usedValues,insertionOrder,generatedTrees,uniqueTrees);

        return uniqueTrees;
    }
};