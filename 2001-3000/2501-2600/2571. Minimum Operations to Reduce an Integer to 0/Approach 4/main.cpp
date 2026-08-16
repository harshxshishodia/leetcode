class Solution {
public:
    int minOperations(int n) {
        int answer = 0;

        while (n > 0) {
            if ((n & 1) == 0) {
                n >>= 1;
                continue;
            }

            answer++;

            if (n == 1 ||
                (n & 3) == 1) {
                n -= 1;
            } else {
                n += 1;
            }
        }

        return answer;
    }
};
