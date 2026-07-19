class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int answer = INT_MIN;

        for (int start = 0; start < n; start++) {
            int sum = 0;

            for (int end = start; end < n; end++) {
                sum += nums[end];
                answer = max(answer, sum);
            }
        }

        return answer;
    }
};