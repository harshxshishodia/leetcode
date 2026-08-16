class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long prefix = 1;
        long long suffix = 1;
        long long answer = numeric_limits<long long>::min();
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; i++) {
            if (prefix == 0) {
                prefix = 1;
            }

            if (suffix == 0) {
                suffix = 1;
            }

            prefix *= nums[i];
            suffix *= nums[n - 1 - i];
            answer = max({answer, prefix, suffix});
        }

        return static_cast<int>(answer);
    }
};
