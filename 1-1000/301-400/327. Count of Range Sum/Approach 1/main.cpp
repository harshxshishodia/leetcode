class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        int answer = 0;

        for (int index = 0; index < n; index++)
            prefix[index + 1] = prefix[index] + nums[index];

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                long long sum = prefix[right + 1] - prefix[left];

                if (sum >= lower && sum <= upper)
                    answer++;
            }
        }

        return answer;
    }
};