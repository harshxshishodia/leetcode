class Solution {
    vector<vector<pair<int, int>>> children;

    pair<long long, long long> solve(int node) {
        long long parentFree = 0;

        vector<pair<
            pair<long long, long long>,
            int
        >> childData;

        for (auto [child, weight] :
             children[node]) {
            auto result =
                solve(child);

            childData.push_back({
                result,
                weight
            });

            parentFree +=
                result.first;
        }

        long long parentMatched =
            parentFree;

        for (auto item : childData) {
            long long childFree =
                item.first.first;

            long long childBlocked =
                item.first.second;

            int weight =
                item.second;

            parentMatched = max(
                parentMatched,
                parentFree -
                childFree +
                childBlocked +
                weight
            );
        }

        return {
            parentMatched,
            parentFree
        };
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

        auto result =
            solve(0);

        return result.first;
    }
};
