class Solution {
    long long solve(
        const vector<vector<int>>& questions,
        int index
    ) {
        if (index >=
            static_cast<int>(questions.size())) {
            return 0;
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

        return max(
            skip,
            take
        );
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        return solve(
            questions,
            0
        );
    }
};
