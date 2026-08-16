class Solution {
public:
    int minimumSplits(vector<int>& nums) {
        for (int value : nums) {
            if (value == 1) {
                return -1;
            }
        }

        int answer = 1;
        int currentGcd =
            nums[0];

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            int nextGcd =
                gcd(
                    currentGcd,
                    nums[index]
                );

            if (nextGcd > 1) {
                currentGcd =
                    nextGcd;
            } else {
                answer++;
                currentGcd =
                    nums[index];
            }
        }

        return answer;
    }
};
