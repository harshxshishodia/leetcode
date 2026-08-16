class Solution {
public:
    vector<int> shortestDistanceColor(
        vector<int>& colors,
        vector<vector<int>>& queries
    ) {
        vector<int> answer;

        for (const vector<int>& query : queries) {
            int index = query[0];
            int color = query[1];

            int best =
                numeric_limits<int>::max();

            for (int i = 0;
                 i < static_cast<int>(colors.size());
                 i++) {
                if (colors[i] == color) {
                    best = min(
                        best,
                        abs(i - index)
                    );
                }
            }

            answer.push_back(
                best == numeric_limits<int>::max()
                    ? -1
                    : best
            );
        }

        return answer;
    }
};
