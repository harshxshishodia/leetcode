class Solution {
public:
    vector<int> shortestDistanceColor(
        vector<int>& colors,
        vector<vector<int>>& queries
    ) {
        array<vector<int>, 4> positions;

        for (int i = 0;
             i < static_cast<int>(colors.size());
             i++) {
            positions[colors[i]].push_back(i);
        }

        vector<int> answer;

        for (const vector<int>& query : queries) {
            int index = query[0];
            int color = query[1];

            const vector<int>& indices =
                positions[color];

            if (indices.empty()) {
                answer.push_back(-1);
                continue;
            }

            auto position = lower_bound(
                indices.begin(),
                indices.end(),
                index
            );

            int best =
                numeric_limits<int>::max();

            if (position != indices.end()) {
                best = min(
                    best,
                    abs(*position - index)
                );
            }

            if (position != indices.begin()) {
                position--;

                best = min(
                    best,
                    abs(*position - index)
                );
            }

            answer.push_back(best);
        }

        return answer;
    }
};
