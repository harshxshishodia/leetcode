class Solution {
    static constexpr int MOD =
        1000000007;

    vector<int> nums;
    vector<bool> used;

    int search(
        int last,
        int count
    ) {
        if (count ==
            static_cast<int>(nums.size())) {
            return 1;
        }

        long long answer = 0;

        for (int index = 0;
             index < static_cast<int>(nums.size());
             index++) {
            if (used[index]) {
                continue;
            }

            if (last != -1 &&
                nums[last] % nums[index] != 0 &&
                nums[index] % nums[last] != 0) {
                continue;
            }

            used[index] = true;

            answer +=
                search(
                    index,
                    count + 1
                );

            answer %=
                MOD;

            used[index] = false;
        }

        return static_cast<int>(
            answer
        );
    }

public:
    int specialPerm(vector<int>& input) {
        nums =
            input;

        used.assign(
            nums.size(),
            false
        );

        return search(
            -1,
            0
        );
    }
};
