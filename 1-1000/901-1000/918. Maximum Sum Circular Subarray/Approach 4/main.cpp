class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maximumEnding = 0;
        int minimumEnding = 0;

        int maximum =
            nums[0];

        int minimum =
            nums[0];

        for (int number : nums) {
            maximumEnding = max(
                number,
                maximumEnding + number
            );

            maximum = max(
                maximum,
                maximumEnding
            );

            minimumEnding = min(
                number,
                minimumEnding + number
            );

            minimum = min(
                minimum,
                minimumEnding
            );

            total += number;
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
