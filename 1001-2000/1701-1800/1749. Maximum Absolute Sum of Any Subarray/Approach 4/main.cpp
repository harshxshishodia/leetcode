class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maximumEnding = 0;
        int minimumEnding = 0;
        int answer = 0;

        for (int value : nums) {
            maximumEnding = max(
                0,
                maximumEnding + value
            );

            minimumEnding = min(
                0,
                minimumEnding + value
            );

            answer = max({
                answer,
                maximumEnding,
                -minimumEnding
            });
        }

        return answer;
    }
};
