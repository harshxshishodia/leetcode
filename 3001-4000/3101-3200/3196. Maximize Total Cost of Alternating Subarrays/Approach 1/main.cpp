class Solution {
    long long segmentCost(
        const vector<int>& nums,
        int left,
        int right
    ) {
        long long answer = 0;
        int sign = 1;

        for (int index = left;
             index <= right;
             index++) {
            answer +=
                1LL *
                sign *
                nums[index];

            sign *=
                -1;
        }

        return answer;
    }

    long long solve(
        const vector<int>& nums,
        int index
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            return 0;
        }

        long long answer =
            numeric_limits<long long>::min() /
            4;

        for (int end = index;
             end < static_cast<int>(nums.size());
             end++) {
            answer = max(
                answer,
                segmentCost(
                    nums,
                    index,
                    end
                ) +
                solve(
                    nums,
                    end + 1
                )
            );
        }

        return answer;
    }

public:
    long long maximumTotalCost(vector<int>& nums) {
        return solve(
            nums,
            0
        );
    }
};
