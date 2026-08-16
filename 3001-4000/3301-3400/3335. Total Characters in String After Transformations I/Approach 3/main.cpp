class Solution {
public:
    int lengthAfterTransformations(
        string s,
        int t
    ) {
        const long long MOD =
            1000000007;

        array<long long, 26> count = {};

        for (char character :
             s) {
            count[
                character -
                'a'
            ]++;
        }

        while (t > 0) {
            array<long long, 26> next = {};

            for (int character = 0;
                 character < 25;
                 character++) {
                next[character + 1] =
                    (
                        next[character + 1] +
                        count[character]
                    ) %
                    MOD;
            }

            next[0] =
                (
                    next[0] +
                    count[25]
                ) %
                MOD;

            next[1] =
                (
                    next[1] +
                    count[25]
                ) %
                MOD;

            count =
                next;

            t--;
        }

        long long answer = 0;

        for (long long value :
             count) {
            answer +=
                value;

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
