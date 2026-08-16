class Solution {
    int solve(
        const vector<pair<int, int>>& players,
        int index,
        int previous
    ) {
        if (index == static_cast<int>(players.size())) {
            return 0;
        }

        int skip =
            solve(
                players,
                index + 1,
                previous
            );

        int take = 0;

        if (previous == -1 ||
            players[index].second >=
            players[previous].second) {
            take =
                players[index].second +
                solve(
                    players,
                    index + 1,
                    index
                );
        }

        return max(
            skip,
            take
        );
    }

public:
    int bestTeamScore(
        vector<int>& scores,
        vector<int>& ages
    ) {
        vector<pair<int, int>> players;

        for (int i = 0;
             i < static_cast<int>(scores.size());
             i++) {
            players.push_back({
                ages[i],
                scores[i]
            });
        }

        sort(
            players.begin(),
            players.end()
        );

        return solve(
            players,
            0,
            -1
        );
    }
};
