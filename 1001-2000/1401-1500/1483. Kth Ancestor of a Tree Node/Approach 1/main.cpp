class TreeAncestor {
    static const int LOG_MAX = 20;
    vector<vector<int>> ancestorTable;

public:
    TreeAncestor(int n, vector<int>& parent) : ancestorTable(n, vector<int>(LOG_MAX, -1)) {
        for (int i = 0; i < n; i++) {
            ancestorTable[i][0] = parent[i];
        }
        for (int j = 1; j < LOG_MAX; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestorTable[i][j - 1] != -1) {
                    ancestorTable[i][j] = ancestorTable[ancestorTable[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG_MAX; j++) {
            if ((k >> j) & 1) {
                node = ancestorTable[node][j];
                if (node == -1) break;
            }
        }
        return node;
    }
};
