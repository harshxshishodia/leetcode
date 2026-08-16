class Solution {
    int solve(
        const string& s,
        int index,
        int balance,
        vector<vector<int>>& memo
    ) {
        if (balance < 0) {
            return 0;
        }

        if (index == static_cast<int>(s.size())) {
            return balance == 0;
        }

        if (memo[index][balance] != -1) {
            return memo[index][balance];
        }

        bool possible;

        if (s[index] == '(') {
            possible = solve(
                s,
                index + 1,
                balance + 1,
                memo
            );
        } else if (s[index] == ')') {
            possible = solve(
                s,
                index + 1,
                balance - 1,
                memo
            );
        } else {
            possible =
                solve(
                    s,
                    index + 1,
                    balance,
                    memo
                ) ||
                solve(
                    s,
                    index + 1,
                    balance + 1,
                    memo
                ) ||
                solve(
                    s,
                    index + 1,
                    balance - 1,
                    memo
                );
        }

        memo[index][balance] = possible;
        return memo[index][balance];
    }

public:
    bool checkValidString(string s) {
        int n = static_cast<int>(s.size());

        vector<vector<int>> memo(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(
            s,
            0,
            0,
            memo
        );
    }
};
