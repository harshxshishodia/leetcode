class Solution {
    int solve(
        int n,
        int k,
        const vector<vector<int>>& stayScore,
        const vector<vector<int>>& travelScore,
        int day,
        int city
    ) {
        if (day == k) {
            return 0;
        }

        int answer =
            stayScore[day][city] +
            solve(
                n,
                k,
                stayScore,
                travelScore,
                day + 1,
                city
            );

        for (int destination = 0;
             destination < n;
             destination++) {
            if (destination == city) {
                continue;
            }

            answer = max(
                answer,
                travelScore[city][destination] +
                solve(
                    n,
                    k,
                    stayScore,
                    travelScore,
                    day + 1,
                    destination
                )
            );
        }

        return answer;
    }

public:
    int maxScore(
        int n,
        int k,
        vector<vector<int>>& stayScore,
        vector<vector<int>>& travelScore
    ) {
        int answer = 0;

        for (int city = 0;
             city < n;
             city++) {
            answer = max(
                answer,
                solve(
                    n,
                    k,
                    stayScore,
                    travelScore,
                    0,
                    city
                )
            );
        }

        return answer;
    }
};
