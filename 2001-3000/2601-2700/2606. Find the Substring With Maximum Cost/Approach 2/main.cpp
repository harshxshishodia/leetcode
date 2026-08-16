class Solution {
public:
    int maximumCostSubstring(
        string s,
        string chars,
        vector<int>& vals
    ) {
        array<int, 26> cost;

        for (int index = 0; index < 26; index++) {
            cost[index] =
                index + 1;
        }

        for (int index = 0;
             index < static_cast<int>(chars.size());
             index++) {
            cost[
                chars[index] -
                'a'
            ] =
                vals[index];
        }

        vector<int> dp(
            s.size()
        );

        int answer = 0;

        for (int index = 0;
             index < static_cast<int>(s.size());
             index++) {
            int value =
                cost[
                    s[index] -
                    'a'
                ];

            dp[index] = max(
                value,
                (
                    index > 0
                        ? dp[index - 1]
                        : 0
                ) +
                value
            );

            answer = max(
                answer,
                dp[index]
            );
        }

        return answer;
    }
};
