class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        long long answer =
            numeric_limits<long long>::min();

        for (int left = 0; left < n; left++) {
            long long sum = 0;
            int sign = 1;

            for (int right = left; right < n; right++) {
                sum +=
                    1LL *
                    sign *
                    nums[right];

                sign *= -1;

                answer = max(
                    answer,
                    sum
                );
            }
        }

        return answer;
    }
};
