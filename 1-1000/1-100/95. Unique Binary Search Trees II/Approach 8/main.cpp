// Approach 8: Incrementally insert the new maximum value

class Solution {
private:
    TreeNode* cloneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* clonedRoot =
            new TreeNode(root->val);

        clonedRoot->left =
            cloneTree(root->left);

        clonedRoot->right =
            cloneTree(root->right);

        return clonedRoot;
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
    // O(n * Cn) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<TreeNode*> currentTrees = {
            nullptr
        };

        for (int newValue = 1; newValue <= n; newValue++) {
            vector<TreeNode*> nextTrees;

            for (TreeNode* existingTree : currentTrees) {
                TreeNode* newRoot =
                    new TreeNode(newValue);

                newRoot->left =
                    cloneTree(existingTree);

                nextTrees.push_back(newRoot);

                TreeNode* rightSpineNode =
                    existingTree;

                int insertionDepth = 0;

                while (rightSpineNode != nullptr) {
                    TreeNode* clonedTree =
                        cloneTree(existingTree);

                    TreeNode* insertionParent =
                        clonedTree;

                    for (
                        int depth = 0;
                        depth < insertionDepth;
                        depth++
                    ) {
                        insertionParent =
                            insertionParent->right;
                    }

                    TreeNode* insertedNode =
                        new TreeNode(newValue);

                    insertedNode->left =
                        insertionParent->right;

                    insertionParent->right =
                        insertedNode;

                    nextTrees.push_back(clonedTree);

                    rightSpineNode =
                        rightSpineNode->right;

                    insertionDepth++;
                }
            }

            for (TreeNode* existingTree : currentTrees) {
                deleteTree(existingTree);
            }

            currentTrees = move(nextTrees);
        }

        return currentTrees;
    }
};