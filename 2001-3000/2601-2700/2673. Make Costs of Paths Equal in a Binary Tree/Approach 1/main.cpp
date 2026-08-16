class Solution {
    int answer = 0;

    int solve(
        int node,
        int n,
        const vector<int>& cost
    ) {
        if (node > n) {
            return 0;
        }

        int left =
            solve(
                node * 2,
                n,
                cost
            );

        int right =
            solve(
                node * 2 + 1,
                n,
                cost
            );

        answer +=
            abs(
                left -
                right
            );

        return
            cost[node - 1] +
            max(
                left,
                right
            );
    }

public:
    int minIncrements(
        int n,
        vector<int>& cost
    ) {
        answer = 0;

        solve(
            1,
            n,
            cost
        );

        return answer;
    }
};
