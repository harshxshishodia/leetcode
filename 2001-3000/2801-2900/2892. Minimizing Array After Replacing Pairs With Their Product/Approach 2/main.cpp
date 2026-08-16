class Solution {
    vector<int> memo;

    int solve(
        const vector<int>& nums,
        int k,
        int index
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int answer =
            1 +
            solve(
                nums,
                k,
                index + 1
            );

        long long product =
            nums[index];

        for (int end = index + 1;
             end < static_cast<int>(nums.size());
             end++) {
            if (product >
                k /
                nums[end]) {
                break;
            }

            product *=
                nums[end];

            answer = min(
                answer,
                1 +
                solve(
                    nums,
                    k,
                    end + 1
                )
            );
        }

        memo[index] =
            answer;

        return answer;
    }

public:
    int minArrayLength(
        vector<int>& nums,
        int k
    ) {
        for (int value : nums) {
            if (value == 0) {
                return 1;
            }
        }

        memo.assign(
            nums.size(),
            -1
        );

        return solve(
            nums,
            k,
            0
        );
    }
};
