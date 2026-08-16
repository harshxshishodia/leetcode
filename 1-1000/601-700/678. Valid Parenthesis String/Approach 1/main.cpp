class Solution {
    bool solve(
        const string& s,
        int index,
        int balance
    ) {
        if (balance < 0) {
            return false;
        }

        if (index == static_cast<int>(s.size())) {
            return balance == 0;
        }

        if (s[index] == '(') {
            return solve(
                s,
                index + 1,
                balance + 1
            );
        }

        if (s[index] == ')') {
            return solve(
                s,
                index + 1,
                balance - 1
            );
        }

        return
            solve(
                s,
                index + 1,
                balance
            ) ||
            solve(
                s,
                index + 1,
                balance + 1
            ) ||
            solve(
                s,
                index + 1,
                balance - 1
            );
    }

public:
    bool checkValidString(string s) {
        return solve(
            s,
            0,
            0
        );
    }
};
