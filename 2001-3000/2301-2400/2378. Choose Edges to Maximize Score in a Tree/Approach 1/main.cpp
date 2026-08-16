class Solution {
    long long answer = 0;

    void search(
        const vector<vector<int>>& edges,
        int edgeIndex,
        vector<bool>& used,
        long long score
    ) {
        int n =
            static_cast<int>(edges.size());

        if (edgeIndex == n) {
            answer = max(
                answer,
                score
            );

            return;
        }

        search(
            edges,
            edgeIndex + 1,
            used,
            score
        );

        int parent =
            edges[edgeIndex][0];

        int weight =
            edges[edgeIndex][1];

        if (parent != -1 &&
            !used[parent] &&
            !used[edgeIndex]) {
            used[parent] = true;
            used[edgeIndex] = true;

            search(
                edges,
                edgeIndex + 1,
                used,
                score + weight
            );

            used[parent] = false;
            used[edgeIndex] = false;
        }
    }

public:
    long long maxScore(vector<vector<int>>& edges) {
        answer = 0;

        vector<bool> used(
            edges.size()
        );

        search(
            edges,
            1,
            used,
            0
        );

        return answer;
    }
};
