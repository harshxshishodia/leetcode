class Solution {
public:
    int sumOfCompatibleNumbers(int n, int k) {
        int left = max(1, n - k);
        int right = n + k;
        int bits = 0;

        while ((1LL << bits) <= right) {
            bits++;
        }

        int fullMask = (1 << bits) - 1;
        int allowedMask = fullMask ^ (n & fullMask);
        int answer = 0;
        int x = allowedMask;

        while (true) {
            if (x >= left && x <= right) {
                answer += x;
            }

            if (x == 0) {
                break;
            }

            x = (x - 1) & allowedMask;
        }

        return answer;
    }
};
