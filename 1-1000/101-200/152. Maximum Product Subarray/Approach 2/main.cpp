class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long answer = numeric_limits<long long>::min();

        for (int left = 0; left < n; left++) {
            long long product = 1;

            for (int right = left; right < n; right++) {
                product *= nums[right];
                answer = max(answer, product);
            }
        }

        return static_cast<int>(answer);
    }
};
