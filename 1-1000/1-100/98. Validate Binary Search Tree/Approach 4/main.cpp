// Approach 4: Compare every node with all ancestor constraints

class Solution {
private:
    struct AncestorConstraint {
        long long ancestorValue;
        bool mustBeSmaller;
    };

    bool validateTree(
        TreeNode* currentNode,
        vector<AncestorConstraint>& constraints
    ) {
        if (currentNode == nullptr) {
            return true;
        }

        for (const AncestorConstraint& constraint : constraints) {
            if (
                constraint.mustBeSmaller &&
                currentNode->val >= constraint.ancestorValue
            ) {
                return false;
            }

            if (
                !constraint.mustBeSmaller &&
                currentNode->val <= constraint.ancestorValue
            ) {
                return false;
            }
        }

        constraints.push_back({currentNode->val, true});
        bool leftSubtreeIsValid = validateTree(
            currentNode->left,
            constraints
        );
        constraints.pop_back();

        if (!leftSubtreeIsValid) {
            return false;
        }

        constraints.push_back({currentNode->val, false});
        bool rightSubtreeIsValid = validateTree(
            currentNode->right,
            constraints
        );
        constraints.pop_back();

        return rightSubtreeIsValid;
    }

public:
    // O(nh) | O(h)
    bool isValidBST(TreeNode* root) {
        vector<AncestorConstraint> constraints;

        return validateTree(root, constraints);
    }
};