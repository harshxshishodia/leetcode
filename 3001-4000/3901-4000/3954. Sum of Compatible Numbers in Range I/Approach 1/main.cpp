class Solution {
public:
    int sumOfCompatibleNumbers(int n, int k) {
        int left = max(1, n - k);
        int right = n + k;
        int answer = 0;

        for (int x = left; x <= right; x++) {
            if ((n & x) == 0) {
                answer += x;
            }
        }

        return answer;
    }
};
