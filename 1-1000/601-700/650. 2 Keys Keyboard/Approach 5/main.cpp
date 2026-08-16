class Solution {
public:
    int minSteps(int n) {
        int answer = 0;

        for (int factor = 2; factor * factor <= n; factor++) {
            while (n % factor == 0) {
                answer += factor;
                n /= factor;
            }
        }

        if (n > 1) {
            answer += n;
        }

        return answer;
    }
};
