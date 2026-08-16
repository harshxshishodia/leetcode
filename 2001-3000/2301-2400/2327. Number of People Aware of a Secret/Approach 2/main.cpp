class Solution {
public:
    int peopleAwareOfSecret(
        int n,
        int delay,
        int forget
    ) {
        const long long MOD =
            1000000007;

        vector<long long> learned(
            n + 1
        );

        learned[1] = 1;

        long long sharing = 0;

        for (int day = 2;
             day <= n;
             day++) {
            if (day - delay >= 1) {
                sharing +=
                    learned[day - delay];
            }

            if (day - forget >= 1) {
                sharing -=
                    learned[day - forget];
            }

            sharing %=
                MOD;

            if (sharing < 0) {
                sharing +=
                    MOD;
            }

            learned[day] =
                sharing;
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
