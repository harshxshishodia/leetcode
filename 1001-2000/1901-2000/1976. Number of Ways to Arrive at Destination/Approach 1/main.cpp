class Solution {
    long long bestDistance;
    long long count;

    void search(
        const vector<vector<pair<int, int>>>& graph,
        int node,
        int destination,
        long long distance,
        vector<bool>& visited
    ) {
        if (distance > bestDistance) {
            return;
        }

        if (node == destination) {
            if (distance < bestDistance) {
                bestDistance = distance;
                count = 1;
            } else if (distance == bestDistance) {
                count++;
            }

            return;
        }

        visited[node] = true;

        for (auto [next, weight] : graph[node]) {
            if (!visited[next]) {
                search(
                    graph,
                    next,
                    destination,
                    distance + weight,
                    visited
                );
            }
        }

        visited[node] = false;
    }

public:
    int countPaths(
        int n,
        vector<vector<int>>& roads
    ) {
        const int MOD =
            1000000007;

        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int>& road : roads) {
            graph[road[0]].push_back({
                road[1],
                road[2]
            });

            graph[road[1]].push_back({
                road[0],
                road[2]
            });
        }

        bestDistance =
            numeric_limits<long long>::max();

        count = 0;

        vector<bool> visited(n);

        search(
            graph,
            0,
            n - 1,
            0,
            visited
        );

        return static_cast<int>(
            count % MOD
        );
    }
};
