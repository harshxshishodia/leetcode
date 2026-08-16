class Solution {
public:
    bool canReach(
        string s,
        int minJump,
        int maxJump
    ) {
        int n =
            static_cast<int>(s.size());

        vector<int> reachable(n);
        reachable[0] = 1;

        int window = 0;

        for (int index = 1; index < n; index++) {
            if (index - minJump >= 0) {
                window +=
                    reachable[index - minJump];
            }

            if (index - maxJump - 1 >= 0) {
                window -=
                    reachable[index - maxJump - 1];
            }

            if (s[index] == '0' &&
                window > 0) {
                reachable[index] = 1;
            }
        }

        return reachable[n - 1];
    }
};
