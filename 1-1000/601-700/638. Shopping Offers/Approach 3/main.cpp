class Solution {
    unordered_map<string, int> memo;
    vector<vector<int>> offers;

    string encode(const vector<int>& needs) {
        string key;

        for (int value : needs) {
            key += to_string(value);
            key += '#';
        }

        return key;
    }

    int solve(
        const vector<int>& price,
        vector<int>& needs
    ) {
        string key = encode(needs);

        auto found = memo.find(key);

        if (found != memo.end()) {
            return found->second;
        }

        int answer = 0;

        for (int i = 0; i < static_cast<int>(needs.size()); i++) {
            answer += needs[i] * price[i];
        }

        for (const vector<int>& offer : offers) {
            bool applicable = true;

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                if (offer[i] > needs[i]) {
                    applicable = false;
                    break;
                }
            }

            if (!applicable) {
                continue;
            }

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                needs[i] -= offer[i];
            }

            answer = min(
                answer,
                offer.back() + solve(price, needs)
            );

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                needs[i] += offer[i];
            }
        }

        memo[key] = answer;
        return memo[key];
    }

public:
    int shoppingOffers(
        vector<int>& price,
        vector<vector<int>>& special,
        vector<int>& needs
    ) {
        offers.clear();
        memo.clear();

        for (const vector<int>& offer : special) {
            int regularCost = 0;
            bool useful = false;

            for (int i = 0; i < static_cast<int>(needs.size()); i++) {
                regularCost += offer[i] * price[i];
                useful = useful || offer[i] > 0;
            }

            if (useful && offer.back() < regularCost) {
                offers.push_back(offer);
            }
        }

        return solve(price, needs);
    }
};
