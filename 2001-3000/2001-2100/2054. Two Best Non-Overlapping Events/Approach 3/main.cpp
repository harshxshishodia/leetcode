class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(
            events.begin(),
            events.end()
        );

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > active;

        int bestFinished = 0;
        int answer = 0;

        for (const vector<int>& event : events) {
            int start =
                event[0];

            int end =
                event[1];

            int value =
                event[2];

            while (!active.empty() &&
                   active.top().first < start) {
                bestFinished = max(
                    bestFinished,
                    active.top().second
                );

                active.pop();
            }

            answer = max(
                answer,
                bestFinished +
                value
            );

            active.push({
                end,
                value
            });
        }

        return answer;
    }
};
