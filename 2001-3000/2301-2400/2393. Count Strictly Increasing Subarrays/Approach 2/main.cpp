class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        long long answer = 0;

        for (int left = 0; left < n; left++) {
            answer++;

            for (int right = left + 1;
                 right < n;
                 right++) {
                if (nums[right] <=
                    nums[right - 1]) {
                    break;
                }

                answer++;
            }
        }

        return answer;
    }
};
