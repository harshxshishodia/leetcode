class Solution {
    unordered_map<int, int> memo;

    int solve(int n) {
        if (n == 0) {
            return 0;
        }

        if ((n & (n - 1)) == 0) {
            return 1;
        }

        auto found =
            memo.find(n);

        if (found != memo.end()) {
            return found->second;
        }

        int lower = 1;

        while ((lower << 1) < n) {
            lower <<= 1;
        }

        int upper =
            lower << 1;

        int answer =
            1 +
            min(
                solve(
                    n - lower
                ),
                solve(
                    upper - n
                )
            );

        memo[n] =
            answer;

        return answer;
    }

public:
    int minOperations(int n) {
        memo.clear();

        return solve(n);
    }
};
