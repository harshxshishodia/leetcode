class Solution {
public:
    int findTheCity(
        int n,
        vector<vector<int>>& edges,
        int distanceThreshold
    ) {
        const int INF = 1000000000;

        vector<vector<int>> distance(
            n,
            vector<int>(n, INF)
        );

        for (int city = 0; city < n; city++) {
            distance[city][city] = 0;
        }

        for (const vector<int>& edge : edges) {
            distance[edge[0]][edge[1]] = min(
                distance[edge[0]][edge[1]],
                edge[2]
            );

            distance[edge[1]][edge[0]] = min(
                distance[edge[1]][edge[0]],
                edge[2]
            );
        }

        for (int middle = 0; middle < n; middle++) {
            for (int first = 0; first < n; first++) {
                for (int second = 0; second < n; second++) {
                    distance[first][second] = min(
                        distance[first][second],
                        distance[first][middle] +
                        distance[middle][second]
                    );
                }
            }
        }

        int answer = -1;
        int bestCount = n + 1;

        for (int city = 0; city < n; city++) {
            int count = 0;

            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (neighbor != city &&
                    distance[city][neighbor] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= bestCount) {
                bestCount = count;
                answer = city;
            }
        }

        return answer;
    }
};
