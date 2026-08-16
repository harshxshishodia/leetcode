class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        vector<unordered_map<long long, int>> dp(n);

        int answer = 2;

        for (int right = 0; right < n; right++) {
            for (int left = 0; left < right; left++) {
                long long difference =
                    static_cast<long long>(nums[right]) -
                    nums[left];

                int length = 2;

                auto found =
                    dp[left].find(difference);

                if (found != dp[left].end()) {
                    length =
                        found->second +
                        1;
                }

                dp[right][difference] = max(
                    dp[right][difference],
                    length
                );

                answer = max(
                    answer,
                    dp[right][difference]
                );
            }
        }

        return answer;
    }
};
