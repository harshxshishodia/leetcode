class Matrix3D {
    int dimension;
    vector<vector<vector<int>>> matrixGrid;
    vector<int> layerCounts;
    set<pair<int, int>> sortedLayers; // (-count, -x) for descending order

public:
    Matrix3D(int n)
        : dimension(n), matrixGrid(n, vector<vector<int>>(n, vector<int>(n, 0))), layerCounts(n, 0) {
        for (int x = 0; x < n; x++) {
            sortedLayers.insert({0, -x});
        }
    }

    void setCell(int x, int y, int z) {
        if (matrixGrid[x][y][z] == 0) {
            matrixGrid[x][y][z] = 1;
            sortedLayers.erase({-layerCounts[x], -x});
            layerCounts[x]++;
            sortedLayers.insert({-layerCounts[x], -x});
        }
    }

    void unsetCell(int x, int y, int z) {
        if (matrixGrid[x][y][z] == 1) {
            matrixGrid[x][y][z] = 0;
            sortedLayers.erase({-layerCounts[x], -x});
            layerCounts[x]--;
            sortedLayers.insert({-layerCounts[x], -x});
        }
    }

    int largestMatrix() {
        return -sortedLayers.begin()->second;
    }
};
