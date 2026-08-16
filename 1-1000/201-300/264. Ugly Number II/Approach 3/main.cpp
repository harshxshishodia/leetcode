class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ugly(n);
        ugly[0] = 1;

        int index2 = 0;
        int index3 = 0;
        int index5 = 0;

        for (int i = 1; i < n; i++) {
            long long next2 = ugly[index2] * 2;
            long long next3 = ugly[index3] * 3;
            long long next5 = ugly[index5] * 5;
            long long next = min({next2, next3, next5});

            ugly[i] = next;

            if (next == next2) {
                index2++;
            }

            if (next == next3) {
                index3++;
            }

            if (next == next5) {
                index5++;
            }
        }

        return static_cast<int>(ugly[n - 1]);
    }
};
