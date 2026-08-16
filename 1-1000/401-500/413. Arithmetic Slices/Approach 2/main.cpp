class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer = 0;

        for (int left = 0; left + 2 < n; left++) {
            long long difference =
                static_cast<long long>(nums[left + 1]) -
                nums[left];

            for (int right = left + 2; right < n; right++) {
                if (static_cast<long long>(nums[right]) -
                    nums[right - 1] != difference) {
                    break;
                }

                answer++;
            }
        }

        return answer;
    }
};
