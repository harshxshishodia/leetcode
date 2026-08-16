class Solution {
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

        int target = total / 4;
        int n = static_cast<int>(matchsticks.size());

        if (*max_element(
                matchsticks.begin(),
                matchsticks.end()) > target) {
            return false;
        }

        int states = 1 << n;
        vector<int> remainder(states, -1);
        remainder[0] = 0;

        for (int mask = 0; mask < states; mask++) {
            if (remainder[mask] == -1) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                int bit = 1 << i;

                if ((mask & bit) != 0) {
                    continue;
                }

                int next =
                    remainder[mask] + matchsticks[i];

                if (next > target) {
                    continue;
                }

                int nextMask = mask | bit;
                remainder[nextMask] = next % target;
            }
        }

        return remainder[states - 1] == 0;
    }
};
