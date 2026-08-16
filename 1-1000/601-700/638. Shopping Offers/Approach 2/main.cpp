class Solution {
public:
    int shoppingOffers(
        vector<int>& price,
        vector<vector<int>>& special,
        vector<int>& needs
    ) {
        int itemCount = static_cast<int>(needs.size());
        vector<int> base(itemCount);
        int states = 1;

        for (int i = 0; i < itemCount; i++) {
            base[i] = states;
            states *= needs[i] + 1;
        }

        const int INF = 1000000000;
        vector<int> dp(states, INF);
        dp[0] = 0;

        for (int state = 0; state < states; state++) {
            if (dp[state] == INF) {
                continue;
            }

            vector<int> count(itemCount);
            int remainingState = state;

            for (int i = itemCount - 1; i >= 0; i--) {
                count[i] =
                    remainingState / base[i] %
                    (needs[i] + 1);
            }

            for (int item = 0; item < itemCount; item++) {
                if (count[item] == needs[item]) {
                    continue;
                }

                int nextState = state + base[item];

                dp[nextState] = min(
                    dp[nextState],
                    dp[state] + price[item]
                );
            }

            for (const vector<int>& offer : special) {
                bool valid = true;
                int nextState = state;
                int regularCost = 0;
                bool changes = false;

                for (int item = 0; item < itemCount; item++) {
                    if (count[item] + offer[item] > needs[item]) {
                        valid = false;
                        break;
                    }

                    nextState += offer[item] * base[item];
                    regularCost += offer[item] * price[item];
                    changes = changes || offer[item] > 0;
                }

                if (valid && changes && offer.back() < regularCost) {
                    dp[nextState] = min(
                        dp[nextState],
                        dp[state] + offer.back()
                    );
                }
            }
        }

        return dp[states - 1];
    }
};
