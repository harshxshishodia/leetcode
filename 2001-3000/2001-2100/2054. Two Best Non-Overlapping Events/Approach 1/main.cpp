class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n =
            static_cast<int>(events.size());

        int answer = 0;

        for (int first = 0; first < n; first++) {
            answer = max(
                answer,
                events[first][2]
            );

            for (int second = first + 1;
                 second < n;
                 second++) {
                bool nonOverlapping =
                    events[first][1] <
                    events[second][0] ||
                    events[second][1] <
                    events[first][0];

                if (nonOverlapping) {
                    answer = max(
                        answer,
                        events[first][2] +
                        events[second][2]
                    );
                }
            }
        }

        return answer;
    }
};
