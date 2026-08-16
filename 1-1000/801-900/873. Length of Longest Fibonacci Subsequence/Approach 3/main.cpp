class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = static_cast<int>(arr.size());

        unordered_map<int, int> index;

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n, 2)
        );

        int answer = 0;

        for (int second = 0; second < n; second++) {
            for (int third = second + 1; third < n; third++) {
                int firstValue =
                    arr[third] -
                    arr[second];

                auto found =
                    index.find(firstValue);

                if (found != index.end() &&
                    found->second < second) {
                    dp[second][third] =
                        dp[found->second][second] +
                        1;

                    answer = max(
                        answer,
                        dp[second][third]
                    );
                }
            }
        }

        return answer;
    }
};
