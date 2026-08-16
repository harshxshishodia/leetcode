class Solution {
    long long solvePath(
        const vector<pair<int, int>>& values,
        int index,
        int k,
        vector<long long>& memo
    ) {
        if (index ==
            static_cast<int>(values.size())) {
            return 1;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        long long skip =
            solvePath(
                values,
                index + 1,
                k,
                memo
            );

        long long choices =
            (1LL << values[index].second) -
            1;

        int next =
            index + 1;

        if (next <
                static_cast<int>(values.size()) &&
            values[next].first -
                values[index].first ==
                k) {
            next++;
        }

        long long take =
            choices *
            solvePath(
                values,
                next,
                k,
                memo
            );

        memo[index] =
            skip +
            take;

        return memo[index];
    }

public:
    int beautifulSubsets(
        vector<int>& nums,
        int k
    ) {
        map<int, map<int, int>> groups;

        for (int value : nums) {
            groups[value % k][value]++;
        }

        long long total = 1;

        for (auto& [remainder, frequency] :
             groups) {
            vector<pair<int, int>> values(
                frequency.begin(),
                frequency.end()
            );

            vector<long long> memo(
                values.size(),
                -1
            );

            total *=
                solvePath(
                    values,
                    0,
                    k,
                    memo
                );
        }

        return static_cast<int>(
            total - 1
        );
    }
};
