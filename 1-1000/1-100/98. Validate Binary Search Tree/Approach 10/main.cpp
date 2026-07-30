// Approach 10: Bottom-up postorder subtree information

class Solution {
private:
    struct SubtreeInformation {
        bool isValidBST;
        long long minimumValue;
        long long maximumValue;
    };

    SubtreeInformation analyzeSubtree(TreeNode* currentNode) {
        if (currentNode == nullptr) {
            return {
                true,
                LLONG_MAX,
                LLONG_MIN
            };
        }

        SubtreeInformation leftSubtree = analyzeSubtree(
            currentNode->left
        );

        SubtreeInformation rightSubtree = analyzeSubtree(
            currentNode->right
        );

        if (
            !leftSubtree.isValidBST ||
            !rightSubtree.isValidBST
        ) {
            return {
                false,
                0,
                0
            };
        }

        if (
            leftSubtree.maximumValue >= currentNode->val ||
            rightSubtree.minimumValue <= currentNode->val
        ) {
            return {
                false,
                0,
                0
            };
        }

        long long subtreeMinimum = min(
            (long long)currentNode->val,
            leftSubtree.minimumValue
        );

        long long subtreeMaximum = max(
            (long long)currentNode->val,
            rightSubtree.maximumValue
        );

        return {
            true,
            subtreeMinimum,
            subtreeMaximum
        };
    }

public:
    // O(n) | O(h)
    bool isValidBST(TreeNode* root) {
        return analyzeSubtree(root).isValidBST;
    }
};