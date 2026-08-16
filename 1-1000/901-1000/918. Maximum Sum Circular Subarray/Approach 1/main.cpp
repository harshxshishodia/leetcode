class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer =
            numeric_limits<int>::min();

        for (int start = 0; start < n; start++) {
            int sum = 0;

            for (int length = 1;
                 length <= n;
                 length++) {
                int index =
                    (start + length - 1) %
                    n;

                sum += nums[index];

                answer = max(
                    answer,
                    sum
                );
            }
        }

        return answer;
    }
};
