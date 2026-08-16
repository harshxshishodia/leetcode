class Solution {
    long long countComponent(
        const vector<int>& values,
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
            countComponent(
                values,
                index + 1,
                k,
                memo
            );

        int next =
            index + 1;

        if (next <
                static_cast<int>(values.size()) &&
            values[next] -
                values[index] ==
                k) {
            next++;
        }

        long long take =
            countComponent(
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
    long long countTheNumOfKFreeSubsets(
        vector<int>& nums,
        int k
    ) {
        if (k == 0) {
            return
                1LL <<
                nums.size();
        }

        map<int, vector<int>> groups;

        for (int value : nums) {
            groups[value % k].push_back(
                value
            );
        }

        long long answer = 1;

        for (auto& [remainder, values] :
             groups) {
            sort(
                values.begin(),
                values.end()
            );

            vector<long long> memo(
                values.size(),
                -1
            );

            answer *=
                countComponent(
                    values,
                    0,
                    k,
                    memo
                );
        }

        return answer;
    }
};
