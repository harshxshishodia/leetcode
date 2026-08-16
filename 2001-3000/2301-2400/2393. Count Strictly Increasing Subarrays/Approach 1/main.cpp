class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        long long answer = 0;

        for (int left = 0; left < n; left++) {
            for (int right = left;
                 right < n;
                 right++) {
                bool increasing =
                    true;

                for (int index = left + 1;
                     index <= right;
                     index++) {
                    if (nums[index] <=
                        nums[index - 1]) {
                        increasing = false;
                        break;
                    }
                }

                answer +=
                    increasing;
            }
        }

        return answer;
    }
};
