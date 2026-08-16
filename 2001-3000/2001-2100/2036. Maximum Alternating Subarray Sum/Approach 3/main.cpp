class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        const long long NEG =
            numeric_limits<long long>::min() / 4;

        vector<long long> plus(n);
        vector<long long> minus(n, NEG);

        plus[0] =
            nums[0];

        long long answer =
            plus[0];

        for (int index = 1; index < n; index++) {
            plus[index] = max(
                1LL * nums[index],
                minus[index - 1] +
                nums[index]
            );

            minus[index] =
                plus[index - 1] -
                nums[index];

            answer = max({
                answer,
                plus[index],
                minus[index]
            });
        }

        return answer;
    }
};
