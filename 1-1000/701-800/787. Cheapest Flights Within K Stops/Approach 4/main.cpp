class Solution {
public:
    int findCheapestPrice(
        int n,
        vector<vector<int>>& flights,
        int src,
        int dst,
        int k
    ) {
        const int INF = 1000000000;

        vector<int> distance(
            n,
            INF
        );

        distance[src] = 0;

        for (int edges = 0; edges <= k; edges++) {
            vector<int> next = distance;

            for (const vector<int>& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if (distance[from] == INF) {
                    continue;
                }

                next[to] = min(
                    next[to],
                    distance[from] + price
                );
            }

            distance = next;
        }

        return distance[dst] == INF
            ? -1
            : distance[dst];
    }
};
