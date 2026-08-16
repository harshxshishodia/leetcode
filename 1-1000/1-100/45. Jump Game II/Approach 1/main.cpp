class Solution {
    int solve(const vector<int>& nums, int index) {
        int n = static_cast<int>(nums.size());

        if (index >= n - 1) {
            return 0;
        }

        int answer = 1000000000;
        int furthest = min(n - 1, index + nums[index]);

        for (int next = index + 1; next <= furthest; next++) {
            answer = min(answer, 1 + solve(nums, next));
        }

        return answer;
    }

public:
    int jump(vector<int>& nums) {
        return solve(nums, 0);
    }
};
