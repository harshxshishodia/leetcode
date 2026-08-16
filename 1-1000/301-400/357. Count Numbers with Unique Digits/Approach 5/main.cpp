class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        n = min(n, 10);
        int answer = 10;
        int exactLength = 9;
        int available = 9;

        for (int length = 2; length <= n; length++) {
            exactLength *= available;
            answer += exactLength;
            available--;
        }

        return answer;
    }
};
