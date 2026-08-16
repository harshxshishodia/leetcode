class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int>& first, const vector<int>& second) {
                if (first[0] != second[0]) {
                    return first[0] < second[0];
                }

                return first[1] < second[1];
            }
        );

        int n = static_cast<int>(intervals.size());
        vector<int> dp(n, 1);
        int best = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            best = max(best, dp[i]);
        }

        return n - best;
    }
};
