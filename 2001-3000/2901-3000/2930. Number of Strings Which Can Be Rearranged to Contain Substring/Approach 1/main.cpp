class Solution {
    static constexpr int MOD =
        1000000007;

    int n;

    int solve(
        int index,
        int l,
        int e,
        int t
    ) {
        if (index == n) {
            return
                l >= 1 &&
                e >= 2 &&
                t >= 1;
        }

        long long answer = 0;

        for (int character = 0;
             character < 26;
             character++) {
            int nextL =
                l +
                (character == 11);

            int nextE =
                e +
                (character == 4);

            int nextT =
                t +
                (character == 19);

            answer +=
                solve(
                    index + 1,
                    min(
                        nextL,
                        1
                    ),
                    min(
                        nextE,
                        2
                    ),
                    min(
                        nextT,
                        1
                    )
                );

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }

public:
    int stringCount(int inputN) {
        n =
            inputN;

        return solve(
            0,
            0,
            0,
            0
        );
    }
};
