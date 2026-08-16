class Solution {
    int target;
    int best;

    void consider(int cost) {
        if (abs(cost - target) <
            abs(best - target) ||
            (
                abs(cost - target) ==
                abs(best - target) &&
                cost < best
            )) {
            best = cost;
        }
    }

    void search(
        const vector<int>& toppingCosts,
        int index,
        int cost
    ) {
        if (index ==
            static_cast<int>(toppingCosts.size())) {
            consider(cost);
            return;
        }

        search(
            toppingCosts,
            index + 1,
            cost
        );

        search(
            toppingCosts,
            index + 1,
            cost +
            toppingCosts[index]
        );

        search(
            toppingCosts,
            index + 1,
            cost +
            2 *
            toppingCosts[index]
        );
    }

public:
    int closestCost(
        vector<int>& baseCosts,
        vector<int>& toppingCosts,
        int value
    ) {
        target = value;
        best =
            numeric_limits<int>::max();

        for (int base : baseCosts) {
            search(
                toppingCosts,
                0,
                base
            );
        }

        return best;
    }
};
