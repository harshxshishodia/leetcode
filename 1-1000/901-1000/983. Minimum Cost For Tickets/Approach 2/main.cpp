class Solution {
    int solve(
        const vector<int>& days,
        const vector<int>& costs,
        int index,
        vector<int>& memo
    ) {
        if (index == static_cast<int>(days.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int next1 =
            index + 1;

        int next7 =
            lower_bound(
                days.begin(),
                days.end(),
                days[index] + 7
            ) -
            days.begin();

        int next30 =
            lower_bound(
                days.begin(),
                days.end(),
                days[index] + 30
            ) -
            days.begin();

        memo[index] = min({
            costs[0] +
            solve(
                days,
                costs,
                next1,
                memo
            ),
            costs[1] +
            solve(
                days,
                costs,
                next7,
                memo
            ),
            costs[2] +
            solve(
                days,
                costs,
                next30,
                memo
            )
        });

        return memo[index];
    }

public:
    int mincostTickets(
        vector<int>& days,
        vector<int>& costs
    ) {
        vector<int> memo(
            days.size(),
            -1
        );

        return solve(
            days,
            costs,
            0,
            memo
        );
    }
};
