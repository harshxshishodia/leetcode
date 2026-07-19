class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalMoves = m + n - 2;
        int smallerMoves = min(m - 1, n - 1);
        long long paths = 1;

        for (int move = 1; move <= smallerMoves; move++)
            paths = paths * (totalMoves - smallerMoves + move) / move;

        return paths;
    }
};