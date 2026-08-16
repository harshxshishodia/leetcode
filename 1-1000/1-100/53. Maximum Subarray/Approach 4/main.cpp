class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<long long> prefix(n + 1);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        long long minimumPrefix = 0;
        long long answer = numeric_limits<long long>::min();

        for (int right = 1; right <= n; right++) {
            answer = max(answer, prefix[right] - minimumPrefix);
            minimumPrefix = min(minimumPrefix, prefix[right]);
        }

        return static_cast<int>(answer);
    }
};
