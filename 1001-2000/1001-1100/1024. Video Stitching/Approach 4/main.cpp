class Solution {
public:
    int videoStitching(
        vector<vector<int>>& clips,
        int time
    ) {
        vector<int> farthest(
            time + 1
        );

        for (const vector<int>& clip : clips) {
            if (clip[0] <= time) {
                farthest[clip[0]] = max(
                    farthest[clip[0]],
                    clip[1]
                );
            }
        }

        int answer = 0;
        int currentEnd = 0;
        int nextEnd = 0;

        for (int point = 0; point < time; point++) {
            nextEnd = max(
                nextEnd,
                farthest[point]
            );

            if (point == currentEnd) {
                if (nextEnd <= point) {
                    return -1;
                }

                answer++;
                currentEnd = nextEnd;
            }
        }

        return answer;
    }
};
