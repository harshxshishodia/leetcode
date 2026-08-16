class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD =
            1000000007;

        long long answer = 0;

        for (int left = 0;
             left < static_cast<int>(arr.size());
             left++) {
            long long sum = 0;

            for (int right = left;
                 right < static_cast<int>(arr.size());
                 right++) {
                sum += arr[right];

                if (sum % 2 != 0) {
                    answer++;
                }
            }
        }

        return static_cast<int>(
            answer % MOD
        );
    }
};
