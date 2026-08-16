class Solution {
public:
    int longestIdealString(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        vector<int> dp(
            n,
            1
        );

        int answer = 1;

        for (int current = 0;
             current < n;
             current++) {
            for (int previous = 0;
                 previous < current;
                 previous++) {
                if (abs(
                        s[current] -
                        s[previous]
                    ) <= k) {
                    dp[current] = max(
                        dp[current],
                        dp[previous] + 1
                    );
                }
            }

            answer = max(
                answer,
                dp[current]
            );
        }

        return answer;
    }
};
