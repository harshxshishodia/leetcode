// Approach 11: Reconstruct a BST from preorder and compare both trees

class Solution {
private:
    void createPreorderTraversal(
        TreeNode* currentNode,
        vector<int>& preorderValues
    ) {
        if (currentNode == nullptr) {
            return;
        }

        preorderValues.push_back(currentNode->val);

        createPreorderTraversal(
            currentNode->left,
            preorderValues
        );

        createPreorderTraversal(
            currentNode->right,
            preorderValues
        );
    }

    TreeNode* insertIntoBST(
        TreeNode* root,
        int value,
        bool& duplicateExists
    ) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->val) {
            root->left = insertIntoBST(
                root->left,
                value,
                duplicateExists
            );
        } else if (value > root->val) {
            root->right = insertIntoBST(
                root->right,
                value,
                duplicateExists
            );
        } else {
            duplicateExists = true;
        }

        return root;
    }

    bool areIdentical(
        TreeNode* firstTree,
        TreeNode* secondTree
    ) {
        if (
            firstTree == nullptr ||
            secondTree == nullptr
        ) {
            return firstTree == secondTree;
        }

        if (firstTree->val != secondTree->val) {
            return false;
        }

        return (
            areIdentical(
                firstTree->left,
                secondTree->left
            ) &&
            areIdentical(
                firstTree->right,
                secondTree->right
            )
        );
    }

    void deleteTree(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return;
        }

        deleteTree(currentNode->left);
        deleteTree(currentNode->right);

        delete currentNode;
    }

public:
    // O(n^2) | O(n)
    bool isValidBST(TreeNode* root) {
        vector<int> preorderValues;

        createPreorderTraversal(
            root,
            preorderValues
        );

        TreeNode* reconstructedRoot = nullptr;
        bool duplicateExists = false;

        for (int value : preorderValues) {
            reconstructedRoot = insertIntoBST(
                reconstructedRoot,
                value,
                duplicateExists
            );
        }

        bool treesAreIdentical = areIdentical(
            root,
            reconstructedRoot
        );

        deleteTree(reconstructedRoot);

        return (
            !duplicateExists &&
            treesAreIdentical
        );
    }
};