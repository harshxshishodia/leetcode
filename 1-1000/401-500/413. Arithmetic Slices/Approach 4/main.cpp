class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int endingHere = 0;
        int answer = 0;

        for (int i = 2; i < static_cast<int>(nums.size()); i++) {
            if (static_cast<long long>(nums[i]) -
                nums[i - 1] ==
                static_cast<long long>(nums[i - 1]) -
                nums[i - 2]) {
                endingHere++;
                answer += endingHere;
            } else {
                endingHere = 0;
            }
        }

        return answer;
    }
};
