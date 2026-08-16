class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD =
            1000000007;

        long long even = 1;
        long long odd = 0;
        long long prefix = 0;
        long long answer = 0;

        for (int value : arr) {
            prefix += value;

            if (prefix % 2 == 0) {
                answer += odd;
                even++;
            } else {
                answer += even;
                odd++;
            }

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
