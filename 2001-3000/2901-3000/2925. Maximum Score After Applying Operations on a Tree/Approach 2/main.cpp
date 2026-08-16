class Solution {
    vector<vector<int>> tree;
    vector<int> values;

    long long minimumLoss(
        int node,
        int parent
    ) {
        bool leaf = true;
        long long childrenLoss = 0;

        for (int next :
             tree[node]) {
            if (next == parent) {
                continue;
            }

            leaf = false;

            childrenLoss +=
                minimumLoss(
                    next,
                    node
                );
        }

        if (leaf) {
            return values[node];
        }

        return min<long long>(
            values[node],
            childrenLoss
        );
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

        long long total =
            accumulate(
                values.begin(),
                values.end(),
                0LL
            );

        return
            total -
            minimumLoss(
                0,
                -1
            );
    }
};
