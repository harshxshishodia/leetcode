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
            distance[i][colors[i]] = 0;
        }

        for (int color = 1; color <= 3; color++) {
            for (int i = 1; i < n; i++) {
                distance[i][color] = min(
                    distance[i][color],
                    distance[i - 1][color] + 1
                );
            }

            for (int i = n - 2; i >= 0; i--) {
                distance[i][color] = min(
                    distance[i][color],
                    distance[i + 1][color] + 1
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
