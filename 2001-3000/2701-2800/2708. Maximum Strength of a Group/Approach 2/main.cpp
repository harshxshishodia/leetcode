class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long maximum =
            nums[0];

        long long minimum =
            nums[0];

        long long answer =
            nums[0];

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            long long value =
                nums[index];

            long long previousMaximum =
                maximum;

            long long previousMinimum =
                minimum;

            maximum = max({
                value,
                previousMaximum,
                previousMaximum * value,
                previousMinimum * value
            });

            minimum = min({
                value,
                previousMinimum,
                previousMaximum * value,
                previousMinimum * value
            });

            answer = max(
                answer,
                maximum
            );
        }

        return answer;
    }
};
