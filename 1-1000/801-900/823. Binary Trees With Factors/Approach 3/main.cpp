class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1000000007;

        sort(
            arr.begin(),
            arr.end()
        );

        int n = static_cast<int>(arr.size());

        unordered_map<int, int> index;

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        vector<long long> dp(
            n,
            1
        );

        for (int root = 0; root < n; root++) {
            for (int left = 0; left < root; left++) {
                if (arr[root] % arr[left] != 0) {
                    continue;
                }

                int rightValue =
                    arr[root] / arr[left];

                auto found =
                    index.find(rightValue);

                if (found == index.end() ||
                    found->second >= root) {
                    continue;
                }

                dp[root] +=
                    dp[left] *
                    dp[found->second];

                dp[root] %= MOD;
            }
        }

        long long answer = 0;

        for (long long ways : dp) {
            answer += ways;
            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
