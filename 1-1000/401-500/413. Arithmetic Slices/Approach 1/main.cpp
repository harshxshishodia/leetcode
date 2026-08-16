class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer = 0;

        for (int left = 0; left < n; left++) {
            for (int right = left + 2; right < n; right++) {
                bool arithmetic = true;
                long long difference =
                    static_cast<long long>(nums[left + 1]) -
                    nums[left];

                for (int i = left + 2; i <= right; i++) {
                    if (static_cast<long long>(nums[i]) -
                        nums[i - 1] != difference) {
                        arithmetic = false;
                        break;
                    }
                }

                if (arithmetic) {
                    answer++;
                }
            }
        }

        return answer;
    }
};
