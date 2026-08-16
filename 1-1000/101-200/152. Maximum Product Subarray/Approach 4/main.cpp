class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<long long> maximum(n);
        vector<long long> minimum(n);
        maximum[0] = nums[0];
        minimum[0] = nums[0];
        long long answer = nums[0];

        for (int i = 1; i < n; i++) {
            long long value = nums[i];

            maximum[i] = max({
                value,
                value * maximum[i - 1],
                value * minimum[i - 1]
            });

            minimum[i] = min({
                value,
                value * maximum[i - 1],
                value * minimum[i - 1]
            });

            answer = max(answer, maximum[i]);
        }

        return static_cast<int>(answer);
    }
};
