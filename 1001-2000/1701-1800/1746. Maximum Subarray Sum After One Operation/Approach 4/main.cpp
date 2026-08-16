class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int normal =
            nums[0];

        int operated =
            nums[0] *
            nums[0];

        int answer =
            operated;

        for (int i = 1;
             i < static_cast<int>(nums.size());
             i++) {
            int value =
                nums[i];

            int nextOperated = max({
                value * value,
                normal +
                value * value,
                operated +
                value
            });

            int nextNormal = max(
                value,
                normal + value
            );

            normal =
                nextNormal;

            operated =
                nextOperated;

            answer = max(
                answer,
                operated
            );
        }

        return answer;
    }
};
