class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long answer = 0;

        for (int left = 0;
             left < static_cast<int>(nums.size());
             left++) {
            bool hasEven = false;

            for (int right = left;
                 right < static_cast<int>(nums.size());
                 right++) {
                if (nums[right] % 2 == 0) {
                    hasEven = true;
                }

                answer +=
                    hasEven;
            }
        }

        return answer;
    }
};
