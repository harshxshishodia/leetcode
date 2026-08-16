class Solution {
    vector<vector<pair<int, int>>> children;
    vector<array<long long, 2>> memo;
    vector<array<bool, 2>> visited;

    long long solve(
        int node,
        int parentEdgeChosen
    ) {
        if (visited[node][parentEdgeChosen]) {
            return memo[node][parentEdgeChosen];
        }

        visited[node][parentEdgeChosen] = true;

        long long base = 0;

        for (auto [child, weight] :
             children[node]) {
            base +=
                solve(
                    child,
                    0
                );
        }

        long long answer =
            base;

        if (!parentEdgeChosen) {
            for (auto [child, weight] :
                 children[node]) {
                answer = max(
                    answer,
                    base -
                    solve(
                        child,
                        0
                    ) +
                    weight +
                    solve(
                        child,
                        1
                    )
                );
            }
        }

        memo[node][parentEdgeChosen] =
            answer;

        return memo[node][parentEdgeChosen];
    }

public:
    long long maxScore(vector<vector<int>>& edges) {
        int n =
            static_cast<int>(edges.size());

        children.assign(
            n,
            {}
        );

        for (int node = 1;
             node < n;
             node++) {
            children[
                edges[node][0]
            ].push_back({
                node,
                edges[node][1]
            });
        }

        memo.assign(
            n,
            {}
        );

        visited.assign(
            n,
            {}
        );

        return solve(
            0,
            0
        );
    }
};
