class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        const long long NEG =
            numeric_limits<long long>::min() / 4;

        long long plus =
            nums[0];

        long long minus =
            NEG;

        long long answer =
            plus;

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            long long nextPlus = max(
                1LL * nums[index],
                minus + nums[index]
            );

            long long nextMinus =
                plus - nums[index];

            plus =
                nextPlus;

            minus =
                nextMinus;

            answer = max({
                answer,
                plus,
                minus
            });
        }

        return answer;
    }
};
