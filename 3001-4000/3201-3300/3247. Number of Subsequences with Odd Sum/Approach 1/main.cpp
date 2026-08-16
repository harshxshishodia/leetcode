class Solution {
    static constexpr int MOD =
        1000000007;

    long long answer = 0;

    void search(
        const vector<int>& nums,
        int index,
        int parity,
        bool chosen
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            if (chosen &&
                parity == 1) {
                answer++;
                answer %=
                    MOD;
            }

            return;
        }

        search(
            nums,
            index + 1,
            parity,
            chosen
        );

        search(
            nums,
            index + 1,
            parity ^
                (nums[index] & 1),
            true
        );
    }

public:
    int subsequenceCount(vector<int>& nums) {
        answer =
            0;

        search(
            nums,
            0,
            0,
            false
        );

        return static_cast<int>(
            answer
        );
    }
};
