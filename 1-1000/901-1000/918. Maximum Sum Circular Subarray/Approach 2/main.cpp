class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        vector<int> maximumEnding(
            n
        );

        vector<int> minimumEnding(
            n
        );

        maximumEnding[0] = nums[0];
        minimumEnding[0] = nums[0];

        int maximum =
            nums[0];

        int minimum =
            nums[0];

        int total =
            nums[0];

        for (int i = 1; i < n; i++) {
            maximumEnding[i] = max(
                nums[i],
                maximumEnding[i - 1] + nums[i]
            );

            minimumEnding[i] = min(
                nums[i],
                minimumEnding[i - 1] + nums[i]
            );

            maximum = max(
                maximum,
                maximumEnding[i]
            );

            minimum = min(
                minimum,
                minimumEnding[i]
            );

            total += nums[i];
        }

        if (maximum < 0) {
            return maximum;
        }

        return max(
            maximum,
            total - minimum
        );
    }
};
