class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(pressedKeys.size());

        vector<long long> three(
            n + 1
        );

        vector<long long> four(
            n + 1
        );

        three[0] = 1;
        four[0] = 1;

        for (int length = 1; length <= n; length++) {
            for (int take = 1;
                 take <= 3 &&
                 take <= length;
                 take++) {
                three[length] +=
                    three[length - take];
            }

            three[length] %=
                MOD;

            for (int take = 1;
                 take <= 4 &&
                 take <= length;
                 take++) {
                four[length] +=
                    four[length - take];
            }

            four[length] %=
                MOD;
        }

        long long answer = 1;
        int start = 0;

        while (start < n) {
            int end =
                start + 1;

            while (end < n &&
                   pressedKeys[end] ==
                   pressedKeys[start]) {
                end++;
            }

            int length =
                end - start;

            if (pressedKeys[start] == '7' ||
                pressedKeys[start] == '9') {
                answer =
                    answer *
                    four[length] %
                    MOD;
            } else {
                answer =
                    answer *
                    three[length] %
                    MOD;
            }

            start = end;
        }

        return static_cast<int>(answer);
    }
};
