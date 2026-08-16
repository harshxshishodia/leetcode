class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        long long answer = 0;

        for (int left = 0;
             left < static_cast<int>(arr.size());
             left++) {
            int minimum =
                numeric_limits<int>::max();

            for (int right = left;
                 right < static_cast<int>(arr.size());
                 right++) {
                minimum = min(
                    minimum,
                    arr[right]
                );

                answer += minimum;
                answer %= MOD;
            }
        }

        return static_cast<int>(answer);
    }
};
