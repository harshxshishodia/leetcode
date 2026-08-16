class Solution {
public:
    int minHeightShelves(
        vector<vector<int>>& books,
        int shelfWidth
    ) {
        int n =
            static_cast<int>(books.size());

        vector<int> dp(
            n + 1,
            numeric_limits<int>::max()
        );

        dp[0] = 0;

        for (int end = 1; end <= n; end++) {
            int width = 0;
            int height = 0;

            for (int start = end;
                 start >= 1;
                 start--) {
                width +=
                    books[start - 1][0];

                if (width > shelfWidth) {
                    break;
                }

                height = max(
                    height,
                    books[start - 1][1]
                );

                dp[end] = min(
                    dp[end],
                    dp[start - 1] +
                    height
                );
            }
        }

        return dp[n];
    }
};
