class Solution {
public:
    int uniquePaths(int m, int n) {
        int moves = m + n - 2;
        int choose = min(m - 1, n - 1);
        long long answer = 1;

        for (int i = 1; i <= choose; i++) {
            answer = answer * (moves - choose + i) / i;
        }

        return static_cast<int>(answer);
    }
};
