class Solution {
    vector<vector<int>> children;
    vector<int> colors;

    pair<bool, int> inspect(
        int node,
        int color
    ) {
        bool valid =
            colors[node] ==
            color;

        int size = 1;

        for (int child :
             children[node]) {
            auto [
                childValid,
                childSize
            ] =
                inspect(
                    child,
                    color
                );

            valid =
                valid &&
                childValid;

            size +=
                childSize;
        }

        return {
            valid,
            size
        };
    }

public:
    int maximumSubtreeSize(
        vector<vector<int>>& edges,
        vector<int>& inputColors
    ) {
        int n =
            static_cast<int>(inputColors.size());

        vector<vector<int>> graph(
            n
        );

        for (const vector<int>& edge :
             edges) {
            graph[edge[0]].push_back(
                edge[1]
            );

            graph[edge[1]].push_back(
                edge[0]
            );
        }

        children.assign(
            n,
            {}
        );

        vector<int> parent(
            n,
            -1
        );

        queue<int> pending;
        pending.push(0);
        parent[0] = 0;

        while (!pending.empty()) {
            int node =
                pending.front();

            pending.pop();

            for (int next :
                 graph[node]) {
                if (parent[next] != -1) {
                    continue;
                }

                parent[next] =
                    node;

                children[node].push_back(
                    next
                );

                pending.push(
                    next
                );
            }
        }

        colors =
            inputColors;

        int answer = 1;

        for (int node = 0;
             node < n;
             node++) {
            auto [
                valid,
                size
            ] =
                inspect(
                    node,
                    colors[node]
                );

            if (valid) {
                answer = max(
                    answer,
                    size
                );
            }
        }

        return answer;
    }
};
