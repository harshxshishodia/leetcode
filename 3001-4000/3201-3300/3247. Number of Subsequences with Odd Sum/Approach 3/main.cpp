class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        const int MOD =
            1000000007;

        long long even = 0;
        long long odd = 0;

        for (int value : nums) {
            long long nextEven =
                even;

            long long nextOdd =
                odd;

            if (value & 1) {
                nextOdd =
                    (
                        nextOdd +
                        even +
                        1
                    ) %
                    MOD;

                nextEven =
                    (
                        nextEven +
                        odd
                    ) %
                    MOD;
            } else {
                nextEven =
                    (
                        nextEven +
                        even +
                        1
                    ) %
                    MOD;

                nextOdd =
                    (
                        nextOdd +
                        odd
                    ) %
                    MOD;
            }

            even =
                nextEven;

            odd =
                nextOdd;
        }

        return static_cast<int>(
            odd
        );
    }
};
