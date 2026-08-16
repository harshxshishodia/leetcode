class Solution {
    static constexpr int MOD =
        1000000007;

    long long answer = 0;

    void search(
        const vector<int>& nums,
        int k,
        int index,
        int count,
        int minimum,
        int maximum
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            if (count > 0) {
                answer +=
                    minimum;

                answer +=
                    maximum;

                answer %=
                    MOD;
            }

            return;
        }

        search(
            nums,
            k,
            index + 1,
            count,
            minimum,
            maximum
        );

        if (count < k) {
            if (count == 0) {
                search(
                    nums,
                    k,
                    index + 1,
                    1,
                    nums[index],
                    nums[index]
                );
            } else {
                search(
                    nums,
                    k,
                    index + 1,
                    count + 1,
                    min(
                        minimum,
                        nums[index]
                    ),
                    max(
                        maximum,
                        nums[index]
                    )
                );
            }
        }
    }

public:
    int minMaxSums(
        vector<int>& nums,
        int k
    ) {
        answer = 0;

        search(
            nums,
            k,
            0,
            0,
            0,
            0
        );

        return static_cast<int>(
            answer
        );
    }
};
