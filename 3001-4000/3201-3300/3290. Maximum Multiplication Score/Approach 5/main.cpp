class Solution {
public:
    long long maxScore(
        vector<int>& a,
        vector<int>& b
    ) {
        const long long NEG =
            numeric_limits<long long>::min() /
            4;

        array<long long, 5> best = {
            0,
            NEG,
            NEG,
            NEG,
            NEG
        };

        for (int value : b) {
            for (int picked = 3;
                 picked >= 0;
                 picked--) {
                if (best[picked] == NEG) {
                    continue;
                }

                best[picked + 1] = max(
                    best[picked + 1],
                    best[picked] +
                    1LL *
                    a[picked] *
                    value
                );
            }
        }

        return best[4];
    }
};
