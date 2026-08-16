class Solution {
    int solve(int nodes) {
        if (nodes <= 1) {
            return 1;
        }

        int answer = 0;

        for (int root = 1; root <= nodes; root++) {
            int leftTrees = solve(root - 1);
            int rightTrees = solve(nodes - root);
            answer += leftTrees * rightTrees;
        }

        return answer;
    }

public:
    int numTrees(int n) {
        return solve(n);
    }
};
