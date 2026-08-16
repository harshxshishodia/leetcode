class Solution {
public:
    int minimumOperationsToMakeEqual(
        int x,
        int y
    ) {
        if (x == y) {
            return 0;
        }

        int limit =
            2 *
            max(
                x,
                y
            ) +
            20;

        vector<int> distance(
            limit + 1,
            -1
        );

        queue<int> pending;

        distance[x] = 0;
        pending.push(x);

        while (!pending.empty()) {
            int current =
                pending.front();

            pending.pop();

            if (current == y) {
                return distance[current];
            }

            vector<int> nextValues;

            if (current > 0) {
                nextValues.push_back(
                    current -
                    1
                );
            }

            if (current + 1 <= limit) {
                nextValues.push_back(
                    current +
                    1
                );
            }

            if (current % 5 == 0) {
                nextValues.push_back(
                    current /
                    5
                );
            }

            if (current % 11 == 0) {
                nextValues.push_back(
                    current /
                    11
                );
            }

            for (int next :
                 nextValues) {
                if (
                    next < 0 ||
                    next > limit ||
                    distance[next] != -1
                ) {
                    continue;
                }

                distance[next] =
                    distance[current] +
                    1;

                pending.push(
                    next
                );
            }
        }

        return -1;
    }
};
