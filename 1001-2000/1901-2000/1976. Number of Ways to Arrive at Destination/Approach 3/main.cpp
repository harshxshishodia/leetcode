class Solution {
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

        const long long INF =
            numeric_limits<long long>::max() / 4;

        vector<long long> distance(
            n,
            INF
        );

        vector<long long> ways(n);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pending;

        distance[0] = 0;
        ways[0] = 1;

        pending.push({
            0,
            0
        });

        while (!pending.empty()) {
            auto [currentDistance, node] =
                pending.top();

            pending.pop();

            if (currentDistance != distance[node]) {
                continue;
            }

            for (auto [next, weight] : graph[node]) {
                long long nextDistance =
                    currentDistance +
                    weight;

                if (nextDistance < distance[next]) {
                    distance[next] =
                        nextDistance;

                    ways[next] =
                        ways[node];

                    pending.push({
                        nextDistance,
                        next
                    });
                } else if (nextDistance ==
                           distance[next]) {
                    ways[next] +=
                        ways[node];

                    ways[next] %=
                        MOD;
                }
            }
        }

        return static_cast<int>(
            ways[n - 1]
        );
    }
};
