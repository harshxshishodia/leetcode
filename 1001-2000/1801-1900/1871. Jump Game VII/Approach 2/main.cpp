class Solution {
    vector<int> memo;

    int solve(
        const string& s,
        int minJump,
        int maxJump,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size()) - 1) {
            return 1;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        for (int next = index + minJump;
             next < static_cast<int>(s.size()) &&
             next <= index + maxJump;
             next++) {
            if (s[next] == '0' &&
                solve(
                    s,
                    minJump,
                    maxJump,
                    next
                )) {
                return memo[index] = 1;
            }
        }

        return memo[index] = 0;
    }

public:
    bool canReach(
        string s,
        int minJump,
        int maxJump
    ) {
        memo.assign(
            s.size(),
            -1
        );

        return solve(
            s,
            minJump,
            maxJump,
            0
        );
    }
};
