class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD =
            1000000007;

        long long evenEnding = 0;
        long long oddEnding = 0;
        long long answer = 0;

        for (int value : arr) {
            if (value % 2 == 0) {
                evenEnding =
                    evenEnding + 1;
            } else {
                long long previousEven =
                    evenEnding;

                evenEnding =
                    oddEnding;

                oddEnding =
                    previousEven + 1;
            }

            answer +=
                oddEnding;

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
