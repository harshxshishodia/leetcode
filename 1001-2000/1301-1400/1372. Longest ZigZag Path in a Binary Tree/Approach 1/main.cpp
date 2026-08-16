class Solution {
    int answer = 0;

    void walk(
        TreeNode* node,
        bool goLeft,
        int length
    ) {
        if (node == nullptr) {
            return;
        }

        answer = max(
            answer,
            length
        );

        if (goLeft) {
            walk(
                node->left,
                false,
                length + 1
            );

            walk(
                node->right,
                true,
                1
            );
        } else {
            walk(
                node->right,
                true,
                length + 1
            );

            walk(
                node->left,
                false,
                1
            );
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        answer = 0;

        if (root == nullptr) {
            return 0;
        }

        walk(
            root,
            true,
            0
        );

        walk(
            root,
            false,
            0
        );

        return answer;
    }
};
