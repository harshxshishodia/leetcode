class Solution {
    int answer = 0;

    pair<int, int> solve(TreeNode* node) {
        if (node == nullptr) {
            return {-1, -1};
        }

        auto [leftFromLeft, rightFromLeft] =
            solve(node->left);

        auto [leftFromRight, rightFromRight] =
            solve(node->right);

        int goLeft =
            rightFromLeft + 1;

        int goRight =
            leftFromRight + 1;

        answer = max({
            answer,
            goLeft,
            goRight
        });

        return {
            goLeft,
            goRight
        };
    }

public:
    int longestZigZag(TreeNode* root) {
        answer = 0;
        solve(root);
        return answer;
    }
};
