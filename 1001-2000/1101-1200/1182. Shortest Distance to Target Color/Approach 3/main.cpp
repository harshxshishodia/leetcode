class Solution {
public:
    vector<int> shortestDistanceColor(
        vector<int>& colors,
        vector<vector<int>>& queries
    ) {
        int n =
            static_cast<int>(colors.size());

        const int INF =
            1000000000;

        vector<array<int, 4>> distance(n);

        for (int i = 0; i < n; i++) {
            distance[i].fill(INF);
        }

        array<int, 4> last;
        last.fill(-INF);

        for (int i = 0; i < n; i++) {
            last[colors[i]] = i;

            for (int color = 1; color <= 3; color++) {
                distance[i][color] =
                    i - last[color];
            }
        }

        last.fill(INF);

        for (int i = n - 1; i >= 0; i--) {
            last[colors[i]] = i;

            for (int color = 1; color <= 3; color++) {
                distance[i][color] = min(
                    distance[i][color],
                    last[color] - i
                );
            }
        }

        vector<int> answer;

        for (const vector<int>& query : queries) {
            int value =
                distance[query[0]][query[1]];

            answer.push_back(
                value >= INF / 2
                    ? -1
                    : value
            );
        }

        return answer;
    }
};
