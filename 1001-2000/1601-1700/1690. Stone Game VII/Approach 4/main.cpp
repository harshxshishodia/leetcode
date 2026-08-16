class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n =
            static_cast<int>(stones.size());

        vector<int> prefix(
            n + 1
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                stones[i];
        }

        vector<int> dp(n);

        for (int right = 1;
             right < n;
             right++) {
            for (int left = right - 1;
                 left >= 0;
                 left--) {
                int removeLeft =
                    prefix[right + 1] -
                    prefix[left + 1] -
                    dp[left + 1];

                int removeRight =
                    prefix[right] -
                    prefix[left] -
                    dp[left];

                dp[left] = max(
                    removeLeft,
                    removeRight
                );
            }
        }

        return dp[0];
    }
};
