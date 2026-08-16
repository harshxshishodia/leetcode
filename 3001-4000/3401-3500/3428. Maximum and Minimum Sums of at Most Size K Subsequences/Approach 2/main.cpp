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

        vector<vector<long long>> combination(
            n + 1,
            vector<long long>(
                k
            )
        );

        combination[0][0] =
            1;

        for (int total = 1;
             total <= n;
             total++) {
            combination[total][0] =
                1;

            for (int choose = 1;
                 choose < k &&
                 choose <= total;
                 choose++) {
                combination[total][choose] =
                    (
                        combination[total - 1][choose - 1] +
                        combination[total - 1][choose]
                    ) %
                    MOD;
            }
        }

        long long answer = 0;

        for (int index = 0;
             index < n;
             index++) {
            long long asMaximum = 0;
            long long asMinimum = 0;

            for (int chosen = 0;
                 chosen < k;
                 chosen++) {
                if (chosen <= index) {
                    asMaximum +=
                        combination[index][chosen];

                    asMaximum %=
                        MOD;
                }

                int right =
                    n -
                    1 -
                    index;

                if (chosen <= right) {
                    asMinimum +=
                        combination[right][chosen];

                    asMinimum %=
                        MOD;
                }
            }

            answer +=
                1LL *
                nums[index] *
                (
                    asMaximum +
                    asMinimum
                ) %
                MOD;

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
