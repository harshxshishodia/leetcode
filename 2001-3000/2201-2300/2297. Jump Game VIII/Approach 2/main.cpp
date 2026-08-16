class Solution {
public:
    long long minCost(
        vector<int>& nums,
        vector<int>& costs
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<vector<int>> graph(n);

        for (int first = 0; first < n; first++) {
            for (int second = first + 1;
                 second < n;
                 second++) {
                if (nums[second] >=
                    nums[first]) {
                    graph[first].push_back(
                        second
                    );

                    break;
                }
            }

            for (int second = first + 1;
                 second < n;
                 second++) {
                if (nums[second] <
                    nums[first]) {
                    graph[first].push_back(
                        second
                    );

                    break;
                }
            }
        }

        const long long INF =
            numeric_limits<long long>::max() / 4;

        vector<long long> dp(
            n,
            INF
        );

        dp[0] = 0;

        for (int index = 0; index < n; index++) {
            for (int next : graph[index]) {
                dp[next] = min(
                    dp[next],
                    dp[index] +
                    costs[next]
                );
            }
        }

        return dp[n - 1];
    }
};
