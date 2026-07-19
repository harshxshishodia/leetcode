class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int answer = INT_MIN;

        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                int sum = 0;

                for (int index = start; index <= end; index++)
                    sum += nums[index];

                answer = max(answer, sum);
            }
        }

        return answer;
    }
};