class Solution {
public:
    long long numberOfWays(string s) {
        int n =
            static_cast<int>(s.size());

        vector<long long> zeroPrefix(
            n + 1
        );

        vector<long long> onePrefix(
            n + 1
        );

        for (int index = 0; index < n; index++) {
            zeroPrefix[index + 1] =
                zeroPrefix[index] +
                (s[index] == '0');

            onePrefix[index + 1] =
                onePrefix[index] +
                (s[index] == '1');
        }

        long long answer = 0;

        for (int middle = 0; middle < n; middle++) {
            if (s[middle] == '0') {
                long long leftOnes =
                    onePrefix[middle];

                long long rightOnes =
                    onePrefix[n] -
                    onePrefix[middle + 1];

                answer +=
                    leftOnes *
                    rightOnes;
            } else {
                long long leftZeroes =
                    zeroPrefix[middle];

                long long rightZeroes =
                    zeroPrefix[n] -
                    zeroPrefix[middle + 1];

                answer +=
                    leftZeroes *
                    rightZeroes;
            }
        }

        return answer;
    }
};
