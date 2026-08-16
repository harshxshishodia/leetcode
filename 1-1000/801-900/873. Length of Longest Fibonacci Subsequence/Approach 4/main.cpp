class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = static_cast<int>(arr.size());

        vector<vector<int>> dp(
            n,
            vector<int>(n, 2)
        );

        int answer = 0;

        for (int third = 2; third < n; third++) {
            int first = 0;
            int second = third - 1;

            while (first < second) {
                long long sum =
                    static_cast<long long>(arr[first]) +
                    arr[second];

                if (sum < arr[third]) {
                    first++;
                } else if (sum > arr[third]) {
                    second--;
                } else {
                    dp[second][third] =
                        dp[first][second] +
                        1;

                    answer = max(
                        answer,
                        dp[second][third]
                    );

                    first++;
                    second--;
                }
            }
        }

        return answer;
    }
};
