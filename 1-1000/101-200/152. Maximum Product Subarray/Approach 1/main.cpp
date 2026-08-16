class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long answer = numeric_limits<long long>::min();

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                long long product = 1;

                for (int i = left; i <= right; i++) {
                    product *= nums[i];
                }

                answer = max(answer, product);
            }
        }

        return static_cast<int>(answer);
    }
};
