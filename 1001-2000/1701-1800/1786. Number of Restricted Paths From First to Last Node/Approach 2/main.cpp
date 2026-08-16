class Solution {
    static constexpr int MOD =
        1000000007;

    vector<vector<pair<int, int>>> graph;
    vector<long long> distance;
    vector<int> memo;

    int countPaths(int node, int destination) {
        if (node == destination) {
            return 1;
        }

        if (memo[node] != -1) {
            return memo[node];
        }

        long long answer = 0;

        for (auto [next, weight] : graph[node]) {
            if (distance[next] <
                distance[node]) {
                answer +=
                    countPaths(
                        next,
                        destination
                    );

                answer %= MOD;
            }
        }

        memo[node] =
            static_cast<int>(answer);

        return memo[node];
    }

public:
    int countRestrictedPaths(
        int n,
        vector<vector<int>>& edges
    ) {
        graph.assign(
            n + 1,
            {}
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

        distance.assign(
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

        while (!pending.empty()) {
            auto [currentDistance, node] =
                pending.top();

            pending.pop();

            if (currentDistance !=
                distance[node]) {
                continue;
            }

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

        memo.assign(
            n + 1,
            -1
        );

        return countPaths(
            1,
            n
        );
    }
};
