class Solution {
    vector<long long> memo;

    long long solve(
        const vector<vector<int>>& questions,
        int index
    ) {
        if (index >=
            static_cast<int>(questions.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        long long skip =
            solve(
                questions,
                index + 1
            );

        long long take =
            questions[index][0] +
            solve(
                questions,
                index +
                questions[index][1] +
                1
            );

        memo[index] = max(
            skip,
            take
        );

        return memo[index];
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        memo.assign(
            questions.size(),
            -1
        );

        return solve(
            questions,
            0
        );
    }
};
