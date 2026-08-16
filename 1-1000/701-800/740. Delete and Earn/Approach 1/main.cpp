class Solution {
    int solve(
        const vector<pair<int, int>>& values,
        int index
    ) {
        if (index == static_cast<int>(values.size())) {
            return 0;
        }

        int skip = solve(
            values,
            index + 1
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
                next
            );

        return max(skip, take);
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

        return solve(
            values,
            0
        );
    }
};
