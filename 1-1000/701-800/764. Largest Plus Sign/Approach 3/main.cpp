class Solution {
public:
    int orderOfLargestPlusSign(
        int n,
        vector<vector<int>>& mines
    ) {
        vector<vector<int>> dp(
            n,
            vector<int>(n, n)
        );

        for (const vector<int>& mine : mines) {
            dp[mine[0]][mine[1]] = 0;
        }

        for (int row = 0; row < n; row++) {
            int count = 0;

            for (int col = 0; col < n; col++) {
                if (dp[row][col] == 0) {
                    count = 0;
                } else {
                    count++;
                    dp[row][col] = min(
                        dp[row][col],
                        count
                    );
                }
            }

            count = 0;

            for (int col = n - 1; col >= 0; col--) {
                if (dp[row][col] == 0) {
                    count = 0;
                } else {
                    count++;
                    dp[row][col] = min(
                        dp[row][col],
                        count
                    );
                }
            }
        }

        for (int col = 0; col < n; col++) {
            int count = 0;

            for (int row = 0; row < n; row++) {
                if (dp[row][col] == 0) {
                    count = 0;
                } else {
                    count++;
                    dp[row][col] = min(
                        dp[row][col],
                        count
                    );
                }
            }

            count = 0;

            for (int row = n - 1; row >= 0; row--) {
                if (dp[row][col] == 0) {
                    count = 0;
                } else {
                    count++;
                    dp[row][col] = min(
                        dp[row][col],
                        count
                    );
                }
            }
        }

        int answer = 0;

        for (const vector<int>& row : dp) {
            for (int value : row) {
                answer = max(
                    answer,
                    value
                );
            }
        }

        return answer;
    }
};
