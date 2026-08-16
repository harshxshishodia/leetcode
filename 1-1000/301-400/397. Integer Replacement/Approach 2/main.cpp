class Solution {
    int solve(
        long long n,
        unordered_map<long long, int>& memo
    ) {
        if (n == 1) {
            return 0;
        }

        auto found = memo.find(n);

        if (found != memo.end()) {
            return found->second;
        }

        int answer;

        if (n % 2 == 0) {
            answer = 1 + solve(n / 2, memo);
        } else {
            answer = 1 + min(
                solve(n - 1, memo),
                solve(n + 1, memo)
            );
        }

        memo[n] = answer;
        return answer;
    }

public:
    int integerReplacement(int n) {
        unordered_map<long long, int> memo;
        return solve(n, memo);
    }
};
