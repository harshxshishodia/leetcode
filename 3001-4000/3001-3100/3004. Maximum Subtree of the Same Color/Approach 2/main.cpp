class Solution {
    struct SegmentTree {
        int size;
        vector<int> minimum;
        vector<int> maximum;

        SegmentTree(
            const vector<int>& values
        ) {
            size = 1;

            while (size <
                   static_cast<int>(values.size())) {
                size *= 2;
            }

            minimum.assign(
                2 * size,
                numeric_limits<int>::max()
            );

            maximum.assign(
                2 * size,
                numeric_limits<int>::min()
            );

            for (int index = 0;
                 index < static_cast<int>(values.size());
                 index++) {
                minimum[
                    size +
                    index
                ] =
                    values[index];

                maximum[
                    size +
                    index
                ] =
                    values[index];
            }

            for (int node = size - 1;
                 node >= 1;
                 node--) {
                minimum[node] = min(
                    minimum[2 * node],
                    minimum[2 * node + 1]
                );

                maximum[node] = max(
                    maximum[2 * node],
                    maximum[2 * node + 1]
                );
            }
        }

        pair<int, int> query(
            int left,
            int right
        ) {
            left +=
                size;

            right +=
                size;

            int low =
                numeric_limits<int>::max();

            int high =
                numeric_limits<int>::min();

            while (left <= right) {
                if (left % 2 == 1) {
                    low = min(
                        low,
                        minimum[left]
                    );

                    high = max(
                        high,
                        maximum[left]
                    );

                    left++;
                }

                if (right % 2 == 0) {
                    low = min(
                        low,
                        minimum[right]
                    );

                    high = max(
                        high,
                        maximum[right]
                    );

                    right--;
                }

                left /= 2;
                right /= 2;
            }

            return {
                low,
                high
            };
        }
    };

public:
    int maximumSubtreeSize(
        vector<vector<int>>& edges,
        vector<int>& colors
    ) {
        int n =
            static_cast<int>(colors.size());

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

        vector<int> start(n);
        vector<int> finish(n);
        vector<int> order;

        vector<array<int, 3>> stack = {
            {
                0,
                -1,
                0
            }
        };

        while (!stack.empty()) {
            auto [
                node,
                parent,
                state
            ] =
                stack.back();

            stack.pop_back();

            if (state == 0) {
                start[node] =
                    static_cast<int>(
                        order.size()
                    );

                order.push_back(
                    colors[node]
                );

                stack.push_back({
                    node,
                    parent,
                    1
                });

                for (int index =
                         static_cast<int>(
                             graph[node].size()
                         ) -
                         1;
                     index >= 0;
                     index--) {
                    int next =
                        graph[node][index];

                    if (next == parent) {
                        continue;
                    }

                    stack.push_back({
                        next,
                        node,
                        0
                    });
                }
            } else {
                finish[node] =
                    static_cast<int>(
                        order.size()
                    ) -
                    1;
            }
        }

        SegmentTree tree(
            order
        );

        int answer = 1;

        for (int node = 0;
             node < n;
             node++) {
            auto [
                low,
                high
            ] =
                tree.query(
                    start[node],
                    finish[node]
                );

            if (low == high) {
                answer = max(
                    answer,
                    finish[node] -
                    start[node] +
                    1
                );
            }
        }

        return answer;
    }
};
