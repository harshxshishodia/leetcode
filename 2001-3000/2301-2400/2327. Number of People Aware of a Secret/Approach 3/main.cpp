class Solution {
public:
    int peopleAwareOfSecret(
        int n,
        int delay,
        int forget
    ) {
        const long long MOD =
            1000000007;

        vector<long long> difference(
            n + forget + 2
        );

        vector<long long> learned(
            n + 1
        );

        learned[1] = 1;

        if (1 + delay <= n) {
            difference[1 + delay] += 1;
        }

        if (1 + forget <= n) {
            difference[1 + forget] -= 1;
        }

        long long sharing = 0;

        for (int day = 2;
             day <= n;
             day++) {
            sharing +=
                difference[day];

            sharing %=
                MOD;

            if (sharing < 0) {
                sharing +=
                    MOD;
            }

            learned[day] =
                sharing;

            if (day + delay <= n) {
                difference[day + delay] +=
                    learned[day];

                difference[day + delay] %=
                    MOD;
            }

            if (day + forget <= n) {
                difference[day + forget] -=
                    learned[day];

                difference[day + forget] %=
                    MOD;
            }
        }

        long long answer = 0;

        for (int day = max(
                 1,
                 n - forget + 1
             );
             day <= n;
             day++) {
            answer +=
                learned[day];

            answer %=
                MOD;
        }

        return static_cast<int>(answer);
    }
};
