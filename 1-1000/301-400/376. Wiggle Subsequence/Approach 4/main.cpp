class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> up(n, 1);
        vector<int> down(n, 1);
        int answer = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] + 1);
                } else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }

            answer = max({
                answer,
                up[i],
                down[i]
            });
        }

        return answer;
    }
};
