class Solution {
    vector<vector<int>> tree;
    vector<int> values;

    pair<long long, long long> solve(
        int node,
        int parent
    ) {
        bool leaf = true;

        long long subtreeTotal =
            values[node];

        long long scoreIfNodeRemoved =
            values[node];

        long long scoreIfNodeKept = 0;

        for (int next :
             tree[node]) {
            if (next == parent) {
                continue;
            }

            leaf = false;

            auto [
                childTotal,
                childBest
            ] =
                solve(
                    next,
                    node
                );

            subtreeTotal +=
                childTotal;

            scoreIfNodeRemoved +=
                childBest;

            scoreIfNodeKept +=
                childTotal;
        }

        if (leaf) {
            return {
                subtreeTotal,
                0
            };
        }

        return {
            subtreeTotal,
            max(
                scoreIfNodeRemoved,
                scoreIfNodeKept
            )
        };
    }

public:
    long long maximumScoreAfterOperations(
        vector<vector<int>>& edges,
        vector<int>& inputValues
    ) {
        int n =
            static_cast<int>(inputValues.size());

        tree.assign(
            n,
            {}
        );

        for (const vector<int>& edge :
             edges) {
            tree[edge[0]].push_back(
                edge[1]
            );

            tree[edge[1]].push_back(
                edge[0]
            );
        }

        values =
            inputValues;

        return solve(
            0,
            -1
        ).second;
    }
};
