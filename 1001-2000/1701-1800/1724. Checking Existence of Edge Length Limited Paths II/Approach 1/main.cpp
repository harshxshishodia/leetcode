class DistanceLimitedPathsExist {
    int totalNodes;
    vector<vector<int>> ancestorTable;
    vector<vector<int>> maxEdgeTable;
    vector<int> nodeDepths;

    struct DSU {
        vector<int> parent;
        DSU(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }
        int find(int i) { return parent[i] == i ? i : parent[i] = find(parent[i]); }
        bool unite(int i, int j) {
            int rootI = find(i), rootJ = find(j);
            if (rootI != rootJ) { parent[rootI] = rootJ; return true; }
            return false;
        }
    };

    void buildDfs(int u, int p, int d, int w, const vector<vector<pair<int, int>>>& adj) {
        ancestorTable[u][0] = p;
        maxEdgeTable[u][0] = w;
        nodeDepths[u] = d;
        for (int j = 1; j < 18; j++) {
            if (ancestorTable[u][j - 1] != -1) {
                ancestorTable[u][j] = ancestorTable[ancestorTable[u][j - 1]][j - 1];
                maxEdgeTable[u][j] = max(maxEdgeTable[u][j - 1], maxEdgeTable[ancestorTable[u][j - 1]][j - 1]);
            }
        }
        for (const auto& [v, weight] : adj[u]) {
            if (v != p) {
                buildDfs(v, u, d + 1, weight, adj);
            }
        }
    }

public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList)
        : totalNodes(n), ancestorTable(n, vector<int>(18, -1)), maxEdgeTable(n, vector<int>(18, 0)), nodeDepths(n, 0) {
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edgeList) {
            if (dsu.unite(edge[0], edge[1])) {
                adj[edge[0]].emplace_back(edge[1], edge[2]);
                adj[edge[1]].emplace_back(edge[0], edge[2]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (ancestorTable[i][0] == -1) {
                buildDfs(i, -1, 0, 0, adj);
            }
        }
    }

    bool query(int p, int q, int limit) {
        int rootP = p, rootQ = q;
        for (int j = 17; j >= 0; j--) {
            if (ancestorTable[rootP][j] != -1) rootP = ancestorTable[rootP][j];
            if (ancestorTable[rootQ][j] != -1) rootQ = ancestorTable[rootQ][j];
        }
        if (rootP != rootQ) return false;

        int maxPathWeight = 0;
        if (nodeDepths[p] < nodeDepths[q]) swap(p, q);

        for (int j = 17; j >= 0; j--) {
            if (nodeDepths[p] - (1 << j) >= nodeDepths[q]) {
                maxPathWeight = max(maxPathWeight, maxEdgeTable[p][j]);
                p = ancestorTable[p][j];
            }
        }

        if (p == q) return maxPathWeight < limit;

        for (int j = 17; j >= 0; j--) {
            if (ancestorTable[p][j] != ancestorTable[q][j]) {
                maxPathWeight = max({maxPathWeight, maxEdgeTable[p][j], maxEdgeTable[q][j]});
                p = ancestorTable[p][j];
                q = ancestorTable[q][j];
            }
        }

        maxPathWeight = max({maxPathWeight, maxEdgeTable[p][0], maxEdgeTable[q][0]});
        return maxPathWeight < limit;
    }
};
