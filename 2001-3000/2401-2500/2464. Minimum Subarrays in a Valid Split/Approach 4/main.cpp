class Solution {
    vector<int> factors(int value) {
        vector<int> answer;

        for (int divisor = 2;
             1LL *
             divisor *
             divisor <=
             value;
             divisor++) {
            if (value % divisor != 0) {
                continue;
            }

            answer.push_back(
                divisor
            );

            while (value % divisor == 0) {
                value /=
                    divisor;
            }
        }

        if (value > 1) {
            answer.push_back(
                value
            );
        }

        return answer;
    }

public:
    int validSubarraySplit(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        const int INF =
            1000000000;

        vector<int> dp(
            n + 1,
            INF
        );

        dp[0] = 0;

        unordered_map<int, int> best;

        for (int index = 0;
             index < n;
             index++) {
            vector<int> currentFactors =
                factors(
                    nums[index]
                );

            if (dp[index] != INF) {
                for (int prime :
                     currentFactors) {
                    auto found =
                        best.find(
                            prime
                        );

                    if (found == best.end()) {
                        best[prime] =
                            dp[index];
                    } else {
                        found->second = min(
                            found->second,
                            dp[index]
                        );
                    }
                }
            }

            int minimum =
                INF;

            for (int prime :
                 currentFactors) {
                auto found =
                    best.find(
                        prime
                    );

                if (found != best.end()) {
                    minimum = min(
                        minimum,
                        found->second
                    );
                }
            }

            if (minimum != INF) {
                dp[index + 1] =
                    minimum + 1;
            }
        }

        return dp[n] == INF
            ? -1
            : dp[n];
    }
};
