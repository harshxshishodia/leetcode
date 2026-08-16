class Solution {
public:
    int findTheCity(
        int n,
        vector<vector<int>>& edges,
        int distanceThreshold
    ) {
        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back({
                edge[1],
                edge[2]
            });

            graph[edge[1]].push_back({
                edge[0],
                edge[2]
            });
        }

        int answer = -1;
        int bestCount = n + 1;
        const int INF = 1000000000;

        for (int source = 0; source < n; source++) {
            vector<int> distance(n, INF);

            priority_queue<
                pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>
            > pending;

            distance[source] = 0;
            pending.push({0, source});

            while (!pending.empty()) {
                auto [currentDistance, city] =
                    pending.top();

                pending.pop();

                if (currentDistance != distance[city] ||
                    currentDistance > distanceThreshold) {
                    continue;
                }

                for (auto [next, weight] : graph[city]) {
                    int nextDistance =
                        currentDistance + weight;

                    if (nextDistance < distance[next] &&
                        nextDistance <= distanceThreshold) {
                        distance[next] = nextDistance;
                        pending.push({
                            nextDistance,
                            next
                        });
                    }
                }
            }

            int count = 0;

            for (int city = 0; city < n; city++) {
                if (city != source &&
                    distance[city] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= bestCount) {
                bestCount = count;
                answer = source;
            }
        }

        return answer;
    }
};
