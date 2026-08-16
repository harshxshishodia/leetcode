class Solution {
public:
    int maximumEnergy(
        vector<int>& energy,
        int k
    ) {
        int n =
            static_cast<int>(
                energy.size()
            );

        vector<int> dp(
            n
        );

        int answer =
            numeric_limits<int>::min();

        for (int index = n - 1;
             index >= 0;
             index--) {
            dp[index] =
                energy[index] +
                (
                    index +
                    k <
                    n
                        ? dp[
                            index +
                            k
                          ]
                        : 0
                );

            answer = max(
                answer,
                dp[index]
            );
        }

        return answer;
    }
};
