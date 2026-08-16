class Solution {
    int solve(const vector<int>& nums, int index, int previous) {
        if (index == static_cast<int>(nums.size())) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int value = previous; value <= 3; value++) {
            answer = min(
                answer,
                (nums[index] != value) +
                solve(
                    nums,
                    index + 1,
                    value
                )
            );
        }

        return answer;
    }

public:
    int minimumOperations(vector<int>& nums) {
        return solve(
            nums,
            0,
            1
        );
    }
};
