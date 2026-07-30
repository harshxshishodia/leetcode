// Approach 2: Sort the inorder values and rewrite the tree

class Solution {
private:
    void collectInorderValues(
        TreeNode* currentNode,
        vector<int>& inorderValues
    ) {
        if (currentNode == nullptr) {
            return;
        }

        collectInorderValues(
            currentNode->left,
            inorderValues
        );

        inorderValues.push_back(currentNode->val);

        collectInorderValues(
            currentNode->right,
            inorderValues
        );
    }

    void replaceInorderValues(
        TreeNode* currentNode,
        vector<int>& sortedValues,
        int& currentIndex
    ) {
        if (currentNode == nullptr) {
            return;
        }

        replaceInorderValues(
            currentNode->left,
            sortedValues,
            currentIndex
        );

        currentNode->val = sortedValues[currentIndex];
        currentIndex++;

        replaceInorderValues(
            currentNode->right,
            sortedValues,
            currentIndex
        );
    }

public:
    // O(n log n) | O(n)
    void recoverTree(TreeNode* root) {
        vector<int> inorderValues;

        collectInorderValues(
            root,
            inorderValues
        );

        sort(
            inorderValues.begin(),
            inorderValues.end()
        );

        int currentIndex = 0;

        replaceInorderValues(
            root,
            inorderValues,
            currentIndex
        );
    }
};