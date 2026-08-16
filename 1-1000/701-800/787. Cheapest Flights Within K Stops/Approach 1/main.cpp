class Solution {
    static constexpr int INF = 1000000000;

    int solve(
        const vector<vector<pair<int, int>>>& graph,
        int node,
        int destination,
        int edgesRemaining
    ) {
        if (node == destination) {
            return 0;
        }

        if (edgesRemaining == 0) {
            return INF;
        }

        int answer = INF;

        for (auto [next, price] : graph[node]) {
            int remaining = solve(
                graph,
                next,
                destination,
                edgesRemaining - 1
            );

            if (remaining != INF) {
                answer = min(
                    answer,
                    price + remaining
                );
            }
        }

        return answer;
    }

public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int>& flight : flights) {
            graph[flight[0]].push_back({
                flight[1],
                flight[2]
            });
        }

        int answer = solve(
            graph,
            src,
            dst,
            k + 1
        );

        return answer == INF
            ? -1
            : answer;
    }
};
