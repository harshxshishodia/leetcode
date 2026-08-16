class Solution {
    static constexpr int MOD =
        1000000007;

    int n;

    vector<
        vector<
            vector<
                vector<int>
            >
        >
    > memo;

    int solve(
        int index,
        int l,
        int e,
        int t
    ) {
        if (index == n) {
            return
                l == 1 &&
                e == 2 &&
                t == 1;
        }

        int& answer =
            memo[index][l][e][t];

        if (answer != -1) {
            return answer;
        }

        long long total = 0;

        for (int character = 0;
             character < 26;
             character++) {
            int nextL =
                min(
                    1,
                    l +
                    (character == 11)
                );

            int nextE =
                min(
                    2,
                    e +
                    (character == 4)
                );

            int nextT =
                min(
                    1,
                    t +
                    (character == 19)
                );

            total +=
                solve(
                    index + 1,
                    nextL,
                    nextE,
                    nextT
                );

            total %=
                MOD;
        }

        answer =
            static_cast<int>(
                total
            );

        return answer;
    }

public:
    int stringCount(int inputN) {
        n =
            inputN;

        memo.assign(
            n,
            vector<vector<vector<int>>>(
                2,
                vector<vector<int>>(
                    3,
                    vector<int>(
                        2,
                        -1
                    )
                )
            )
        );

        return solve(
            0,
            0,
            0,
            0
        );
    }
};
