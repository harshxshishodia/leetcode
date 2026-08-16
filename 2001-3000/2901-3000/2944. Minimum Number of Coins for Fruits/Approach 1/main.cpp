class Solution {
    int solve(
        const vector<int>& prices,
        int index
    ) {
        int n =
            static_cast<int>(prices.size());

        if (index >= n) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        int right =
            min(
                n,
                2 *
                index +
                2
            );

        for (int next =
                 index +
                 1;
             next <= right;
             next++) {
            answer = min(
                answer,
                prices[index] +
                solve(
                    prices,
                    next
                )
            );
        }

        return answer;
    }

public:
    int minimumCoins(vector<int>& prices) {
        return solve(
            prices,
            0
        );
    }
};
