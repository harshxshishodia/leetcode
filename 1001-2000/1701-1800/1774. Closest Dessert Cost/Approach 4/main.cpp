class Solution {
    void generate(
        const vector<int>& toppings,
        int left,
        int right,
        int index,
        int sum,
        vector<int>& values
    ) {
        if (index == right) {
            values.push_back(sum);
            return;
        }

        generate(
            toppings,
            left,
            right,
            index + 1,
            sum,
            values
        );

        generate(
            toppings,
            left,
            right,
            index + 1,
            sum +
            toppings[index],
            values
        );

        generate(
            toppings,
            left,
            right,
            index + 1,
            sum +
            2 *
            toppings[index],
            values
        );
    }

public:
    int closestCost(
        vector<int>& baseCosts,
        vector<int>& toppingCosts,
        int target
    ) {
        int middle =
            static_cast<int>(toppingCosts.size()) /
            2;

        vector<int> first;
        vector<int> second;

        generate(
            toppingCosts,
            0,
            middle,
            0,
            0,
            first
        );

        generate(
            toppingCosts,
            middle,
            static_cast<int>(toppingCosts.size()),
            middle,
            0,
            second
        );

        sort(
            second.begin(),
            second.end()
        );

        int best =
            baseCosts[0];

        auto consider = [&](int cost) {
            if (abs(cost - target) <
                abs(best - target) ||
                (
                    abs(cost - target) ==
                    abs(best - target) &&
                    cost < best
                )) {
                best = cost;
            }
        };

        for (int base : baseCosts) {
            for (int leftSum : first) {
                int desired =
                    target -
                    base -
                    leftSum;

                auto position =
                    lower_bound(
                        second.begin(),
                        second.end(),
                        desired
                    );

                if (position != second.end()) {
                    consider(
                        base +
                        leftSum +
                        *position
                    );
                }

                if (position != second.begin()) {
                    position--;

                    consider(
                        base +
                        leftSum +
                        *position
                    );
                }
            }
        }

        return best;
    }
};
