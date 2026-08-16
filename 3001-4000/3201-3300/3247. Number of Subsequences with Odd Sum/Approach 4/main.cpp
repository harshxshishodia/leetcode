class Solution {
    static constexpr long long MOD =
        1000000007;

    long long power(
        long long base,
        int exponent
    ) {
        long long answer = 1;

        while (exponent > 0) {
            if (exponent & 1) {
                answer =
                    answer *
                    base %
                    MOD;
            }

            base =
                base *
                base %
                MOD;

            exponent /=
                2;
        }

        return answer;
    }

public:
    int subsequenceCount(vector<int>& nums) {
        bool hasOdd =
            false;

        for (int value : nums) {
            if (value & 1) {
                hasOdd =
                    true;

                break;
            }
        }

        if (!hasOdd) {
            return 0;
        }

        return static_cast<int>(
            power(
                2,
                static_cast<int>(nums.size()) -
                1
            )
        );
    }
};
