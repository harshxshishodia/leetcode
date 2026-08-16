class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer = 0;

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                int negative = 0;
                bool zero = false;

                for (int i = left; i <= right; i++) {
                    if (nums[i] == 0) {
                        zero = true;
                        break;
                    }

                    if (nums[i] < 0) {
                        negative++;
                    }
                }

                if (!zero && negative % 2 == 0) {
                    answer = max(
                        answer,
                        right - left + 1
                    );
                }
            }
        }

        return answer;
    }
};
