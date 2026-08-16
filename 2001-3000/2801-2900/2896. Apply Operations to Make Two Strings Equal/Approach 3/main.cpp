class Solution {
public:
    int minOperations(
        string s1,
        string s2,
        int x
    ) {
        vector<int> positions;

        for (int index = 0;
             index < static_cast<int>(s1.size());
             index++) {
            if (s1[index] !=
                s2[index]) {
                positions.push_back(
                    index
                );
            }
        }

        int count =
            static_cast<int>(positions.size());

        if (count % 2 != 0) {
            return -1;
        }

        if (count == 0) {
            return 0;
        }

        vector<long long> dp(
            count + 1
        );

        dp[1] =
            x;

        for (int length = 2;
             length <= count;
             length++) {
            dp[length] = min(
                dp[length - 1] +
                x,
                dp[length - 2] +
                2LL *
                (
                    positions[length - 1] -
                    positions[length - 2]
                )
            );
        }

        return static_cast<int>(
            dp[count] /
            2
        );
    }
};
