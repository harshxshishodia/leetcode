class Solution {
    int solve(
        const vector<pair<int, int>>& values,
        int index,
        vector<int>& memo
    ) {
        if (index == static_cast<int>(values.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int skip = solve(
            values,
            index + 1,
            memo
        );

        int next = index + 1;

        if (next < static_cast<int>(values.size()) &&
            values[next].first == values[index].first + 1) {
            next++;
        }

        int take =
            values[index].first *
            values[index].second +
            solve(
                values,
                next,
                memo
            );

        memo[index] = max(skip, take);
        return memo[index];
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> frequency;

        for (int number : nums) {
            frequency[number]++;
        }

        vector<pair<int, int>> values(
            frequency.begin(),
            frequency.end()
        );

        vector<int> memo(
            values.size(),
            -1
        );

        return solve(
            values,
            0,
            memo
        );
    }
};
