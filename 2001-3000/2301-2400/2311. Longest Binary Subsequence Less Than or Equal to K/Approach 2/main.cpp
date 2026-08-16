class Solution {
public:
    int longestSubsequence(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        const long long INF =
            numeric_limits<long long>::max() / 4;

        vector<long long> minimumValue(
            n + 1,
            INF
        );

        minimumValue[0] = 0;

        int best = 0;

        for (char bit : s) {
            for (int length = best + 1;
                 length >= 1;
                 length--) {
                if (minimumValue[length - 1] == INF) {
                    continue;
                }

                long long value =
                    minimumValue[length - 1] *
                    2 +
                    (bit - '0');

                if (value <= k) {
                    minimumValue[length] = min(
                        minimumValue[length],
                        value
                    );

                    best = max(
                        best,
                        length
                    );
                }
            }
        }

        int zeroes = count(
            s.begin(),
            s.end(),
            '0'
        );

        return max(
            best,
            zeroes
        );
    }
};
