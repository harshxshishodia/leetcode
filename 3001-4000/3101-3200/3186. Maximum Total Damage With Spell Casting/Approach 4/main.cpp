class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> frequency;

        for (int value : power) {
            frequency[value]++;
        }

        vector<long long> values;
        vector<long long> damage;

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

        int n =
            static_cast<int>(values.size());

        vector<long long> dp(
            n + 1
        );

        for (int index = 1;
             index <= n;
             index++) {
            int compatible =
                lower_bound(
                    values.begin(),
                    values.begin() +
                    index -
                    1,
                    values[index - 1] -
                    2
                ) -
                values.begin();

            long long take =
                damage[index - 1] +
                dp[compatible];

            dp[index] = max(
                dp[index - 1],
                take
            );
        }

        return dp[n];
    }
};
