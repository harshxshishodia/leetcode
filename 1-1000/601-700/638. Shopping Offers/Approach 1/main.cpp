class Solution {
    int solve(
        const vector<int>& price,
        const vector<vector<int>>& special,
        vector<int>& needs
    ) {
        int direct = 0;

        for (int i = 0; i < static_cast<int>(needs.size()); i++) {
            direct += needs[i] * price[i];
        }

        int answer = direct;

        for (const vector<int>& offer : special) {
            bool applicable = true;
            bool changes = false;

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                if (offer[i] > needs[i]) {
                    applicable = false;
                    break;
                }

                if (offer[i] > 0) {
                    changes = true;
                }
            }

            if (!applicable || !changes) {
                continue;
            }

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                needs[i] -= offer[i];
            }

            answer = min(
                answer,
                offer.back() +
                solve(price, special, needs)
            );

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                needs[i] += offer[i];
            }
        }

        return answer;
    }

public:
    int shoppingOffers(
        vector<int>& price,
        vector<vector<int>>& special,
        vector<int>& needs
    ) {
        return solve(price, special, needs);
    }
};
