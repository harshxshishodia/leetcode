class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer = numeric_limits<int>::min();

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                int sum = 0;

                for (int i = left; i <= right; i++) {
                    sum += nums[i];
                }

                answer = max(answer, sum);
            }
        }

        return answer;
    }
};
