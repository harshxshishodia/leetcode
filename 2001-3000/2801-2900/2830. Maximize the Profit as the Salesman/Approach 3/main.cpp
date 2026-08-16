class Solution {
public:
    int maximizeTheProfit(
        int n,
        vector<vector<int>>& offers
    ) {
        sort(
            offers.begin(),
            offers.end(),
            [](const vector<int>& first, const vector<int>& second) {
                if (first[1] != second[1]) {
                    return first[1] < second[1];
                }

                return first[0] < second[0];
            }
        );

        int count =
            static_cast<int>(offers.size());

        vector<int> ends(count);

        for (int index = 0; index < count; index++) {
            ends[index] =
                offers[index][1];
        }

        vector<int> dp(
            count + 1
        );

        for (int index = 1; index <= count; index++) {
            int start =
                offers[index - 1][0];

            int previous =
                upper_bound(
                    ends.begin(),
                    ends.begin() +
                    index -
                    1,
                    start -
                    1
                ) -
                ends.begin();

            dp[index] = max(
                dp[index - 1],
                offers[index - 1][2] +
                dp[previous]
            );
        }

        return dp[count];
    }
};
