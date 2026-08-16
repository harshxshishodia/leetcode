class Solution {
    vector<int> memo;
    int n;

    int solve(int mask) {
        if (mask == (1 << n) - 1) {
            return 1;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        int position = __builtin_popcount(
            static_cast<unsigned int>(mask)
        ) + 1;

        int answer = 0;

        for (int value = 1; value <= n; value++) {
            int bit = 1 << (value - 1);

            if ((mask & bit) != 0) {
                continue;
            }

            if (value % position != 0 &&
                position % value != 0) {
                continue;
            }

            answer += solve(mask | bit);
        }

        memo[mask] = answer;
        return memo[mask];
    }

public:
    int countArrangement(int value) {
        n = value;
        memo.assign(1 << n, -1);
        return solve(0);
    }
};
