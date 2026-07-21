class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int left = 0; left < n; left++) {
            for (int right = left + 1; right < n; right++) {
                if ((long long)nums[left] > 2LL * nums[right])
                    answer++;
            }
        }

        return answer;
    }
};