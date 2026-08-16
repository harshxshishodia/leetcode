class Solution {
public:
    int longestSubsequence(
        vector<int>& arr,
        int difference
    ) {
        int n =
            static_cast<int>(arr.size());

        vector<int> dp(
            n,
            1
        );

        int answer = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] == difference) {
                    dp[i] = max(
                        dp[i],
                        dp[j] + 1
                    );
                }
            }

            answer = max(
                answer,
                dp[i]
            );
        }

        return answer;
    }
};
