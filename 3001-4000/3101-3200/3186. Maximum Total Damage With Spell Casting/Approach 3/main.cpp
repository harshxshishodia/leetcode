class Solution {
    vector<long long> values;
    vector<long long> damage;
    vector<long long> memo;

    long long solve(int index) {
        if (index ==
            static_cast<int>(values.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        long long skip =
            solve(
                index + 1
            );

        int next =
            upper_bound(
                values.begin(),
                values.end(),
                values[index] +
                2
            ) -
            values.begin();

        long long take =
            damage[index] +
            solve(next);

        memo[index] = max(
            skip,
            take
        );

        return memo[index];
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> frequency;

        for (int value : power) {
            frequency[value]++;
        }

        values.clear();
        damage.clear();

        for (auto [value, count] :
             frequency) {
            values.push_back(
                value
            );

            damage.push_back(
                value *
                count
            );
        }

        memo.assign(
            values.size(),
            -1
        );

        return solve(0);
    }
};
