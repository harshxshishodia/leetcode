class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int MOD =
            1000000007;

        int n =
            static_cast<int>(nextVisit.size());

        vector<int> visits(n);

        int room = 0;
        int distinct = 0;
        long long day = 0;

        while (true) {
            if (visits[room] == 0) {
                distinct++;
            }

            visits[room]++;

            if (distinct == n) {
                return static_cast<int>(
                    day % MOD
                );
            }

            if (visits[room] % 2 == 1) {
                room =
                    nextVisit[room];
            } else {
                room =
                    (room + 1) %
                    n;
            }

            day++;
        }
    }
};
