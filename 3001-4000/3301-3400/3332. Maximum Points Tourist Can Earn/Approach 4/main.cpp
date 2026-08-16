class Solution {
public:
    int maxScore(
        int n,
        int k,
        vector<vector<int>>& stayScore,
        vector<vector<int>>& travelScore
    ) {
        vector<int> next(n);

        for (int day = k - 1;
             day >= 0;
             day--) {
            vector<int> current(n);

            for (int city = 0;
                 city < n;
                 city++) {
                current[city] =
                    stayScore[day][city] +
                    next[city];

                for (int destination = 0;
                     destination < n;
                     destination++) {
                    if (destination == city) {
                        continue;
                    }

                    current[city] = max(
                        current[city],
                        travelScore[city][destination] +
                        next[destination]
                    );
                }
            }

            next.swap(
                current
            );
        }

        return *max_element(
            next.begin(),
            next.end()
        );
    }
};
