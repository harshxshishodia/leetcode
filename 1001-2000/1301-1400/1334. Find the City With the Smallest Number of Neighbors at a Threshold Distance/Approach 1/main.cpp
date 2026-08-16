class Solution {
public:
    int findTheCity(
        int n,
        vector<vector<int>>& edges,
        int distanceThreshold
    ) {
        const int INF = 1000000000;
        int answer = -1;
        int bestCount = n + 1;

        for (int source = 0; source < n; source++) {
            vector<int> distance(n, INF);
            distance[source] = 0;

            for (int iteration = 0; iteration < n - 1; iteration++) {
                bool changed = false;

                for (const vector<int>& edge : edges) {
                    int first = edge[0];
                    int second = edge[1];
                    int weight = edge[2];

                    if (distance[first] != INF &&
                        distance[first] + weight < distance[second]) {
                        distance[second] =
                            distance[first] + weight;
                        changed = true;
                    }

                    if (distance[second] != INF &&
                        distance[second] + weight < distance[first]) {
                        distance[first] =
                            distance[second] + weight;
                        changed = true;
                    }
                }

                if (!changed) {
                    break;
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
