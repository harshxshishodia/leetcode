class Solution {
    vector<vector<int>> tree;
    vector<int> values;
    long long answer;

    bool healthy(
        int node,
        int parent,
        const vector<bool>& removed,
        long long pathSum
    ) {
        if (!removed[node]) {
            pathSum +=
                values[node];
        }

        bool leaf = true;

        for (int next :
             tree[node]) {
            if (next == parent) {
                continue;
            }

            leaf = false;

            if (!healthy(
                    next,
                    node,
                    removed,
                    pathSum)) {
                return false;
            }
        }

        if (leaf) {
            return pathSum > 0;
        }

        return true;
    }

    void search(
        int index,
        vector<bool>& removed,
        long long score
    ) {
        if (index ==
            static_cast<int>(values.size())) {
            if (healthy(
                    0,
                    -1,
                    removed,
                    0)) {
                answer = max(
                    answer,
                    score
                );
            }

            return;
        }

        search(
            index + 1,
            removed,
            score
        );

        removed[index] =
            true;

        search(
            index + 1,
            removed,
            score +
            values[index]
        );

        removed[index] =
            false;
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

        answer = 0;

        vector<bool> removed(
            n
        );

        search(
            0,
            removed,
            0
        );

        return answer;
    }
};
