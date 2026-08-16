class Solution {
    bool solve(
        const string& s,
        int minJump,
        int maxJump,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size()) - 1) {
            return true;
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
                return true;
            }
        }

        return false;
    }

public:
    bool canReach(
        string s,
        int minJump,
        int maxJump
    ) {
        return solve(
            s,
            minJump,
            maxJump,
            0
        );
    }
};
