class Solution {
public:
    int minMaxSums(
        vector<int>& nums,
        int k
    ) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(nums.size());

        sort(
            nums.begin(),
            nums.end()
        );

        vector<long long> sumWays(
            n
        );

        vector<long long> row(
            k
        );

        row[0] =
            1;

        for (int total = 0;
             total < n;
             total++) {
            long long sum = 0;

            for (int choose = 0;
                 choose < k;
                 choose++) {
                sum +=
                    row[choose];

                sum %=
                    MOD;
            }

            sumWays[total] =
                sum;

            for (int choose =
                     min(
                         k - 1,
                         total + 1
                     );
                 choose >= 1;
                 choose--) {
                row[choose] =
                    (
                        row[choose] +
                        row[choose - 1]
                    ) %
                    MOD;
            }
        }

        long long answer = 0;

        for (int index = 0;
             index < n;
             index++) {
            long long coefficient =
                (
                    sumWays[index] +
                    sumWays[
                        n -
                        1 -
                        index
                    ]
                ) %
                MOD;

            answer +=
                1LL *
                nums[index] *
                coefficient %
                MOD;

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
