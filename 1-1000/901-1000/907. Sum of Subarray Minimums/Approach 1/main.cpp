class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        long long answer = 0;

        for (int left = 0;
             left < static_cast<int>(arr.size());
             left++) {
            for (int right = left;
                 right < static_cast<int>(arr.size());
                 right++) {
                int minimum = arr[left];

                for (int i = left + 1; i <= right; i++) {
                    minimum = min(
                        minimum,
                        arr[i]
                    );
                }

                answer += minimum;
                answer %= MOD;
            }
        }

        return static_cast<int>(answer);
    }
};
