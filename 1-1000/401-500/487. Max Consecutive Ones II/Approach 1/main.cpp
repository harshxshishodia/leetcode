class Solution {
    int longest(const vector<int>& nums) {
        int answer = 0;
        int current = 0;

        for (int value : nums) {
            if (value == 1) {
                current++;
                answer = max(answer, current);
            } else {
                current = 0;
            }
        }

        return answer;
    }

public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answer = longest(nums);

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == 1) {
                continue;
            }

            nums[i] = 1;
            answer = max(answer, longest(nums));
            nums[i] = 0;
        }

        return answer;
    }
};
