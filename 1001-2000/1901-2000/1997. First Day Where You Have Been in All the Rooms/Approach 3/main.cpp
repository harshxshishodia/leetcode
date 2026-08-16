class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const long long MOD =
            1000000007;

        int n =
            static_cast<int>(nextVisit.size());

        vector<long long> firstDay(n);

        for (int room = 1;
             room < n;
             room++) {
            firstDay[room] =
                (
                    2 *
                    firstDay[room - 1] -
                    firstDay[
                        nextVisit[room - 1]
                    ] +
                    2
                ) %
                MOD;

            if (firstDay[room] < 0) {
                firstDay[room] +=
                    MOD;
            }
        }

        return static_cast<int>(
            firstDay[n - 1]
        );
    }
};
