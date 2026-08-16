class Solution {
    unordered_map<string, bool> memo;

    string encode(
        vector<int> piles
    ) {
        sort(
            piles.begin(),
            piles.end()
        );

        string key;

        for (int pile : piles) {
            key +=
                to_string(pile);

            key += '#';
        }

        return key;
    }

    bool solve(
        vector<int>& piles
    ) {
        string key =
            encode(piles);

        auto found =
            memo.find(key);

        if (found != memo.end()) {
            return found->second;
        }

        bool empty = true;

        for (int pile : piles) {
            if (pile > 0) {
                empty = false;
                break;
            }
        }

        if (empty) {
            return memo[key] = false;
        }

        for (int index = 0;
             index < static_cast<int>(piles.size());
             index++) {
            int original =
                piles[index];

            for (int remaining = 0;
                 remaining < original;
                 remaining++) {
                piles[index] =
                    remaining;

                if (!solve(piles)) {
                    piles[index] =
                        original;

                    return memo[key] = true;
                }
            }

            piles[index] =
                original;
        }

        return memo[key] = false;
    }

public:
    bool nimGame(vector<int>& piles) {
        memo.clear();
        return solve(piles);
    }
};
