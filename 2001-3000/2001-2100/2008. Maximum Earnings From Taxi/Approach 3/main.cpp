class Solution {
public:
    long long maxTaxiEarnings(
        int n,
        vector<vector<int>>& rides
    ) {
        sort(
            rides.begin(),
            rides.end(),
            [](const vector<int>& first, const vector<int>& second) {
                return first[0] < second[0];
            }
        );

        int count =
            static_cast<int>(rides.size());

        vector<long long> dp(
            count + 1
        );

        for (int index = count - 1;
             index >= 0;
             index--) {
            int end =
                rides[index][1];

            int next =
                lower_bound(
                    rides.begin(),
                    rides.end(),
                    end,
                    [](const vector<int>& ride, int value) {
                        return ride[0] < value;
                    }
                ) -
                rides.begin();

            long long take =
                rides[index][1] -
                rides[index][0] +
                rides[index][2] +
                dp[next];

            dp[index] = max(
                dp[index + 1],
                take
            );
        }

        return dp[0];
    }
};
