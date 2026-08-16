class Solution {
public:
    int maxScore(vector<int>& nums) {
        int maximum = 0;
        int answer = 0;

        for (int index =
                 static_cast<int>(nums.size()) -
                 1;
             index >= 1;
             index--) {
            maximum = max(
                maximum,
                nums[index]
            );

            answer +=
                maximum;
        }

        return answer;
    }
};
