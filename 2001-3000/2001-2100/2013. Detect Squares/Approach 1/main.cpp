class DetectSquares {
    int pointGridCounts[1001][1001] = {0};

public:
    DetectSquares() {}

    void add(vector<int> point) {
        pointGridCounts[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int totalSquares = 0;

        for (int y2 = 0; y2 <= 1000; y2++) {
            if (y2 == y || pointGridCounts[x][y2] == 0) continue;
            int sideLength = abs(y2 - y);

            int xLeft = x - sideLength;
            if (xLeft >= 0) {
                totalSquares += pointGridCounts[x][y2] * pointGridCounts[xLeft][y] * pointGridCounts[xLeft][y2];
            }

            int xRight = x + sideLength;
            if (xRight <= 1000) {
                totalSquares += pointGridCounts[x][y2] * pointGridCounts[xRight][y] * pointGridCounts[xRight][y2];
            }
        }
        return totalSquares;
    }
};
