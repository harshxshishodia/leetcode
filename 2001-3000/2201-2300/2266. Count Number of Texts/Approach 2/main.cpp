class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> memo;

    int solve(
        const string& pressedKeys,
        int index
    ) {
        if (index ==
            static_cast<int>(pressedKeys.size())) {
            return 1;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int maximum =
            (
                pressedKeys[index] == '7' ||
                pressedKeys[index] == '9'
            )
                ? 4
                : 3;

        long long answer = 0;

        for (int length = 1;
             length <= maximum &&
             index + length <=
             static_cast<int>(pressedKeys.size());
             length++) {
            if (pressedKeys[index + length - 1] !=
                pressedKeys[index]) {
                break;
            }

            answer +=
                solve(
                    pressedKeys,
                    index + length
                );

            answer %=
                MOD;
        }

        memo[index] =
            static_cast<int>(answer);

        return memo[index];
    }

public:
    int countTexts(string pressedKeys) {
        memo.assign(
            pressedKeys.size(),
            -1
        );

        return solve(
            pressedKeys,
            0
        );
    }
};
