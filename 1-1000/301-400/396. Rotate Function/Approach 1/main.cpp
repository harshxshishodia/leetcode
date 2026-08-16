class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> current = nums;
        long long answer = numeric_limits<long long>::min();

        for (int rotation = 0; rotation < n; rotation++) {
            long long value = 0;

            for (int i = 0; i < n; i++) {
                value += 1LL * i * current[i];
            }

            answer = max(answer, value);

            int last = current[n - 1];

            for (int i = n - 1; i > 0; i--) {
                current[i] = current[i - 1];
            }

            current[0] = last;
        }

        return static_cast<int>(answer);
    }
};
