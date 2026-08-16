class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> maximum(n);
        vector<int> minimum(n);

        maximum[0] =
            nums[0];

        minimum[0] =
            nums[0];

        int answer =
            abs(nums[0]);

        for (int i = 1; i < n; i++) {
            maximum[i] = max(
                nums[i],
                maximum[i - 1] +
                nums[i]
            );

            minimum[i] = min(
                nums[i],
                minimum[i - 1] +
                nums[i]
            );

            answer = max({
                answer,
                abs(maximum[i]),
                abs(minimum[i])
            });
        }

        return answer;
    }
};
