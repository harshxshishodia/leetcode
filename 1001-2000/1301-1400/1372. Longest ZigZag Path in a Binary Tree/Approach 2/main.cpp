class Solution {
    unordered_map<TreeNode*, array<int, 2>> memo;

    int solve(
        TreeNode* node,
        int direction
    ) {
        if (node == nullptr) {
            return -1;
        }

        if (memo.count(node) &&
            memo[node][direction] != -2) {
            return memo[node][direction];
        }

        if (!memo.count(node)) {
            memo[node] = {-2, -2};
        }

        int answer;

        if (direction == 0) {
            answer =
                1 +
                solve(
                    node->left,
                    1
                );
        } else {
            answer =
                1 +
                solve(
                    node->right,
                    0
                );
        }

        memo[node][direction] = answer;
        return answer;
    }

    void traverse(
        TreeNode* node,
        int& answer
    ) {
        if (node == nullptr) {
            return;
        }

        answer = max({
            answer,
            solve(node, 0),
            solve(node, 1)
        });

        traverse(
            node->left,
            answer
        );

        traverse(
            node->right,
            answer
        );
    }

public:
    int longestZigZag(TreeNode* root) {
        memo.clear();
        int answer = 0;
        traverse(
            root,
            answer
        );

        return answer;
    }
};
