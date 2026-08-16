class Solution {
public:
    int countRestrictedPaths(
        int n,
        vector<vector<int>>& edges
    ) {
        const int MOD =
            1000000007;

        vector<vector<pair<int, int>>> graph(
            n + 1
        );

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

        const long long INF =
            numeric_limits<long long>::max() / 4;

        vector<long long> distance(
            n + 1,
            INF
        );

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pending;

        distance[n] = 0;
        pending.push({
            0,
            n
        });

        vector<int> order;
        vector<bool> processed(
            n + 1
        );

        while (!pending.empty()) {
            auto [currentDistance, node] =
                pending.top();

            pending.pop();

            if (processed[node]) {
                continue;
            }

            processed[node] = true;
            order.push_back(node);

            for (auto [next, weight] : graph[node]) {
                long long nextDistance =
                    currentDistance +
                    weight;

                if (nextDistance <
                    distance[next]) {
                    distance[next] =
                        nextDistance;

                    pending.push({
                        nextDistance,
                        next
                    });
                }
            }
        }

        vector<long long> ways(
            n + 1
        );

        ways[n] = 1;

        for (int node : order) {
            for (auto [next, weight] : graph[node]) {
                if (distance[next] >
                    distance[node]) {
                    ways[next] +=
                        ways[node];

                    ways[next] %=
                        MOD;
                }
            }
        }

        return static_cast<int>(
            ways[1]
        );
    }
};
