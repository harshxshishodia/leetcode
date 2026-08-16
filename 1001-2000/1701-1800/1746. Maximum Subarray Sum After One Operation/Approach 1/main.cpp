class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        int answer =
            numeric_limits<int>::min();

        for (int left = 0; left < n; left++) {
            for (int right = left;
                 right < n;
                 right++) {
                int sum = 0;

                for (int i = left; i <= right; i++) {
                    sum += nums[i];
                }

                for (int operated = left;
                     operated <= right;
                     operated++) {
                    int candidate =
                        sum -
                        nums[operated] +
                        nums[operated] *
                        nums[operated];

                    answer = max(
                        answer,
                        candidate
                    );
                }
            }
        }

        return answer;
    }
};
