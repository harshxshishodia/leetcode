class TicTacToe {
    vector<int> rowCounts;
    vector<int> colCounts;
    int diagonalCount;
    int antiDiagonalCount;
    int boardSize;

public:
    TicTacToe(int n) : boardSize(n), rowCounts(n, 0), colCounts(n, 0), diagonalCount(0), antiDiagonalCount(0) {}

    int move(int row, int col, int player) {
        int delta = (player == 1 ? 1 : -1);
        rowCounts[row] += delta;
        colCounts[col] += delta;
        if (row == col) diagonalCount += delta;
        if (row + col == boardSize - 1) antiDiagonalCount += delta;

        if (abs(rowCounts[row]) == boardSize || abs(colCounts[col]) == boardSize ||
            abs(diagonalCount) == boardSize || abs(antiDiagonalCount) == boardSize) {
            return player;
        }
        return 0;
    }
};
