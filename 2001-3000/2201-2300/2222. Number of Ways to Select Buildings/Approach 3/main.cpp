class Solution {
public:
    long long numberOfWays(string s) {
        long long zero = 0;
        long long one = 0;
        long long zeroOne = 0;
        long long oneZero = 0;
        long long answer = 0;

        for (char building : s) {
            if (building == '0') {
                answer +=
                    zeroOne;

                oneZero +=
                    one;

                zero++;
            } else {
                answer +=
                    oneZero;

                zeroOne +=
                    zero;

                one++;
            }
        }

        return answer;
    }
};
