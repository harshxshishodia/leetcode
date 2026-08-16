class Solution {
    vector<vector<int>> tree;
    vector<int> colors;
    int answer;

    pair<int, bool> solve(
        int node,
        int parent
    ) {
        int size = 1;
        bool uniform = true;

        for (int next :
             tree[node]) {
            if (next == parent) {
                continue;
            }

            auto [
                childSize,
                childUniform
            ] =
                solve(
                    next,
                    node
                );

            size +=
                childSize;

            if (
                !childUniform ||
                colors[next] !=
                colors[node]
            ) {
                uniform =
                    false;
            }
        }

        if (uniform) {
            answer = max(
                answer,
                size
            );
        }

        return {
            size,
            uniform
        };
    }

public:
    int maximumSubtreeSize(
        vector<vector<int>>& edges,
        vector<int>& inputColors
    ) {
        int n =
            static_cast<int>(inputColors.size());

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

        colors =
            inputColors;

        answer = 1;

        solve(
            0,
            -1
        );

        return answer;
    }
};
