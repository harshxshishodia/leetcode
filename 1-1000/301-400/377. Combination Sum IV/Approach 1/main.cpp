class Solution {
    int solve(
        const vector<int>& nums,
        int remaining
    ) {
        if (remaining == 0) {
            return 1;
        }

        int answer = 0;

        for (int number : nums) {
            if (number <= remaining) {
                answer += solve(
                    nums,
                    remaining - number
                );
            }
        }

        return answer;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};
