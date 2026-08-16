class Solution {
    int solve(
        const vector<int>& days,
        const vector<int>& costs,
        int index
    ) {
        if (index == static_cast<int>(days.size())) {
            return 0;
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

        return min({
            costs[0] +
            solve(
                days,
                costs,
                next1
            ),
            costs[1] +
            solve(
                days,
                costs,
                next7
            ),
            costs[2] +
            solve(
                days,
                costs,
                next30
            )
        });
    }

public:
    int mincostTickets(
        vector<int>& days,
        vector<int>& costs
    ) {
        return solve(
            days,
            costs,
            0
        );
    }
};
