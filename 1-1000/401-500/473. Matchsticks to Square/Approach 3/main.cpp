class Solution {
    int target;
    vector<int> memo;

    bool solve(
        const vector<int>& matchsticks,
        int mask,
        int currentSide
    ) {
        if (mask == (1 << matchsticks.size()) - 1) {
            return currentSide == 0;
        }

        if (memo[mask] != -1) {
            return memo[mask];
        }

        for (int i = 0; i < static_cast<int>(matchsticks.size()); i++) {
            int bit = 1 << i;

            if ((mask & bit) != 0) {
                continue;
            }

            if (currentSide + matchsticks[i] > target) {
                continue;
            }

            int nextSide =
                (currentSide + matchsticks[i]) % target;

            if (solve(
                    matchsticks,
                    mask | bit,
                    nextSide)) {
                return memo[mask] = 1;
            }
        }

        return memo[mask] = 0;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(
            matchsticks.begin(),
            matchsticks.end(),
            0
        );

        if (total % 4 != 0 || matchsticks.empty()) {
            return false;
        }

        target = total / 4;

        if (*max_element(
                matchsticks.begin(),
                matchsticks.end()) > target) {
            return false;
        }

        memo.assign(1 << matchsticks.size(), -1);

        return solve(
            matchsticks,
            0,
            0
        );
    }
};
