class Graph {
    int nodeCount;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    Graph(int n, vector<vector<int>>& edges) : nodeCount(n), adjacencyList(n) {
        for (const auto& edge : edges) {
            addEdge(edge);
        }
    }

    void addEdge(vector<int> edge) {
        adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
    }

    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> minDistance(nodeCount, INT_MAX);

        minDistance[node1] = 0;
        minHeap.emplace(0, node1);

        while (!minHeap.empty()) {
            auto [dist, u] = minHeap.top();
            minHeap.pop();

            if (dist > minDistance[u]) continue;
            if (u == node2) return dist;

            for (const auto& [v, weight] : adjacencyList[u]) {
                if (minDistance[u] + weight < minDistance[v]) {
                    minDistance[v] = minDistance[u] + weight;
                    minHeap.emplace(minDistance[v], v);
                }
            }
        }
        return -1;
    }
};
