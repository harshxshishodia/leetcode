class Solution {
public:
    int closestCost(
        vector<int>& baseCosts,
        vector<int>& toppingCosts,
        int target
    ) {
        int limit =
            target +
            2 *
            accumulate(
                toppingCosts.begin(),
                toppingCosts.end(),
                0
            ) +
            *max_element(
                baseCosts.begin(),
                baseCosts.end()
            );

        vector<bool> possible(
            limit + 1
        );

        for (int base : baseCosts) {
            if (base <= limit) {
                possible[base] = true;
            }
        }

        for (int topping : toppingCosts) {
            vector<bool> next =
                possible;

            for (int cost = 0; cost <= limit; cost++) {
                if (!possible[cost]) {
                    continue;
                }

                if (cost + topping <= limit) {
                    next[cost + topping] =
                        true;
                }

                if (cost + 2 * topping <= limit) {
                    next[cost + 2 * topping] =
                        true;
                }
            }

            possible = next;
        }

        int best = -1;

        for (int cost = 0; cost <= limit; cost++) {
            if (!possible[cost]) {
                continue;
            }

            if (best == -1 ||
                abs(cost - target) <
                abs(best - target) ||
                (
                    abs(cost - target) ==
                    abs(best - target) &&
                    cost < best
                )) {
                best = cost;
            }
        }

        return best;
    }
};
