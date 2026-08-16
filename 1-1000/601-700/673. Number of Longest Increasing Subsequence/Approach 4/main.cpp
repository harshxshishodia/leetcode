class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> length(n, 1);
        vector<int> count(n, 1);

        int bestLength = 0;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) {
                    continue;
                }

                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }

            if (length[i] > bestLength) {
                bestLength = length[i];
                answer = count[i];
            } else if (length[i] == bestLength) {
                answer += count[i];
            }
        }

        return answer;
    }
};
