class Solution {
    static constexpr long long MOD =
        1000000007;

    vector<long long> memo;
    vector<bool> visited;
    vector<int>* nextVisit;

    long long firstDay(int room) {
        if (room == 0) {
            return 0;
        }

        if (visited[room]) {
            return memo[room];
        }

        visited[room] = true;

        long long previous =
            firstDay(
                room - 1
            );

        long long revisit =
            firstDay(
                (*nextVisit)[room - 1]
            );

        memo[room] =
            (
                2 * previous -
                revisit +
                2
            ) %
            MOD;

        if (memo[room] < 0) {
            memo[room] +=
                MOD;
        }

        return memo[room];
    }

public:
    int firstDayBeenInAllRooms(vector<int>& input) {
        nextVisit = &input;

        memo.assign(
            input.size(),
            0
        );

        visited.assign(
            input.size(),
            false
        );

        return static_cast<int>(
            firstDay(
                static_cast<int>(input.size()) - 1
            )
        );
    }
};
