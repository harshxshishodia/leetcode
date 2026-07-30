// Approach 1: Try swapping every possible pair and validate the BST
// Genuine brute-force approach

class Solution {
private:
    void collectNodes(TreeNode* currentNode, vector<TreeNode*>& nodes) {
        if (currentNode == nullptr) {
            return;
        }

        nodes.push_back(currentNode);

        collectNodes(currentNode->left, nodes);
        collectNodes(currentNode->right, nodes);
    }

    bool validateBST(
        TreeNode* currentNode,
        long long lowerBound,
        long long upperBound
    ) {
        if (currentNode == nullptr) {
            return true;
        }

        if (
            currentNode->val <= lowerBound ||
            currentNode->val >= upperBound
        ) {
            return false;
        }

        return (
            validateBST(
                currentNode->left,
                lowerBound,
                currentNode->val
            ) &&
            validateBST(
                currentNode->right,
                currentNode->val,
                upperBound
            )
        );
    }

public:
    // O(n^3) | O(n)
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        collectNodes(root, nodes);

        for (
            int firstIndex = 0;
            firstIndex < nodes.size();
            firstIndex++
        ) {
            for (
                int secondIndex = firstIndex + 1;
                secondIndex < nodes.size();
                secondIndex++
            ) {
                swap(
                    nodes[firstIndex]->val,
                    nodes[secondIndex]->val
                );

                if (
                    validateBST(
                        root,
                        LLONG_MIN,
                        LLONG_MAX
                    )
                ) {
                    return;
                }

                swap(
                    nodes[firstIndex]->val,
                    nodes[secondIndex]->val
                );
            }
        }
    }
};