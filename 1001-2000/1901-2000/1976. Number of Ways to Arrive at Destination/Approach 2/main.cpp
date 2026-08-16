class Solution {
    static constexpr int MOD =
        1000000007;

    vector<vector<pair<int, int>>> graph;
    vector<long long> distance;
    vector<int> memo;

    int solve(
        int node,
        int destination
    ) {
        if (node == destination) {
            return 1;
        }

        if (memo[node] != -1) {
            return memo[node];
        }

        long long answer = 0;

        for (auto [next, weight] : graph[node]) {
            if (distance[node] ==
                distance[next] + weight) {
                answer +=
                    solve(
                        next,
                        destination
                    );

                answer %=
                    MOD;
            }
        }

        memo[node] =
            static_cast<int>(answer);

        return memo[node];
    }

public:
    int countPaths(
        int n,
        vector<vector<int>>& roads
    ) {
        graph.assign(
            n,
            {}
        );

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

        distance.assign(
            n,
            INF
        );

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pending;

        distance[n - 1] = 0;

        pending.push({
            0,
            n - 1
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

                    pending.push({
                        nextDistance,
                        next
                    });
                }
            }
        }

        memo.assign(
            n,
            -1
        );

        return solve(
            0,
            n - 1
        );
    }
};
