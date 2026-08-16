class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long maximumEnding = nums[0];
        long long minimumEnding = nums[0];
        long long answer = nums[0];

        for (int i = 1; i < static_cast<int>(nums.size()); i++) {
            long long value = nums[i];

            if (value < 0) {
                swap(maximumEnding, minimumEnding);
            }

            maximumEnding = max(value, maximumEnding * value);
            minimumEnding = min(value, minimumEnding * value);
            answer = max(answer, maximumEnding);
        }

        return static_cast<int>(answer);
    }
};
