class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        long long total = 0;
        long long current = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            current += 1LL * i * nums[i];
        }

        long long answer = current;

        for (int rotation = 1; rotation < n; rotation++) {
            current =
                current +
                total -
                1LL * n * nums[n - rotation];

            answer = max(answer, current);
        }

        return static_cast<int>(answer);
    }
};
