class Excel {
    int height, width;
    vector<vector<int>> cellGridValues;
    map<pair<int, int>, vector<string>> cellFormulas;

public:
    Excel(int H, char W)
        : height(H), width(W - 'A' + 1), cellGridValues(H + 1, vector<int>(W - 'A' + 2, 0)) {}

    void set(int row, char column, int val) {
        int col = column - 'A' + 1;
        cellFormulas.erase({row, col});
        cellGridValues[row][col] = val;
    }

    int get(int row, char column) {
        int col = column - 'A' + 1;
        if (cellFormulas.count({row, col})) {
            return sum(row, column, cellFormulas[{row, col}]);
        }
        return cellGridValues[row][col];
    }

    int sum(int row, char column, vector<string> numbers) {
        int col = column - 'A' + 1;
        cellFormulas[{row, col}] = numbers;
        int totalSum = 0;

        for (const string& s : numbers) {
            int colonPos = s.find(':');
            if (colonPos == string::npos) {
                int c = s[0] - 'A' + 1;
                int r = stoi(s.substr(1));
                totalSum += get(r, s[0]);
            } else {
                string startCell = s.substr(0, colonPos);
                string endCell = s.substr(colonPos + 1);
                int startCol = startCell[0] - 'A' + 1;
                int startRow = stoi(startCell.substr(1));
                int endCol = endCell[0] - 'A' + 1;
                int endRow = stoi(endCell.substr(1));

                for (int r = startRow; r <= endRow; r++) {
                    for (int c = startCol; c <= endCol; c++) {
                        totalSum += get(r, static_cast<char>('A' + c - 1));
                    }
                }
            }
        }
        cellGridValues[row][col] = totalSum;
        return totalSum;
    }
};
