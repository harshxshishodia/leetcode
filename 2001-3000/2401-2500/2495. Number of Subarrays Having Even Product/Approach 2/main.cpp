class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long answer = 0;
        long long endingEven = 0;

        for (int index = 0;
             index < static_cast<int>(nums.size());
             index++) {
            if (nums[index] % 2 == 0) {
                endingEven =
                    index + 1;
            }

            answer +=
                endingEven;
        }

        return answer;
    }
};
