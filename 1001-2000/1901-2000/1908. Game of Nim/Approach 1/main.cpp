class Solution {
    bool solve(
        vector<int>& piles
    ) {
        bool empty = true;

        for (int pile : piles) {
            if (pile > 0) {
                empty = false;
                break;
            }
        }

        if (empty) {
            return false;
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

                    return true;
                }
            }

            piles[index] =
                original;
        }

        return false;
    }

public:
    bool nimGame(vector<int>& piles) {
        return solve(piles);
    }
};
