class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> normal(n);
        vector<int> operated(n);

        normal[0] = nums[0];
        operated[0] =
            nums[0] *
            nums[0];

        int answer =
            operated[0];

        for (int i = 1; i < n; i++) {
            normal[i] = max(
                nums[i],
                normal[i - 1] +
                nums[i]
            );

            operated[i] = max({
                nums[i] *
                nums[i],
                normal[i - 1] +
                nums[i] *
                nums[i],
                operated[i - 1] +
                nums[i]
            });

            answer = max(
                answer,
                operated[i]
            );
        }

        return answer;
    }
};
