class Solution {
    vector<vector<pair<int, int>>> starting;
    vector<int> memo;

    int solve(int house, int n) {
        if (house >= n) {
            return 0;
        }

        if (memo[house] != -1) {
            return memo[house];
        }

        int answer =
            solve(
                house + 1,
                n
            );

        for (auto [end, gold] :
             starting[house]) {
            answer = max(
                answer,
                gold +
                solve(
                    end + 1,
                    n
                )
            );
        }

        memo[house] =
            answer;

        return answer;
    }

public:
    int maximizeTheProfit(
        int n,
        vector<vector<int>>& offers
    ) {
        starting.assign(
            n,
            {}
        );

        for (const vector<int>& offer :
             offers) {
            starting[
                offer[0]
            ].push_back({
                offer[1],
                offer[2]
            });
        }

        memo.assign(
            n,
            -1
        );

        return solve(
            0,
            n
        );
    }
};
