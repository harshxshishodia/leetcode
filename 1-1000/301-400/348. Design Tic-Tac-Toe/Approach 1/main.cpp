class TicTacToe {
    vector<vector<int>> board;
    int size;

public:
    TicTacToe(int n) : size(n), board(n, vector<int>(n, 0)) {}

    int move(int row, int col, int player) {
        board[row][col] = player;

        bool rowWin = true, colWin = true, diagWin = true, antiDiagWin = true;
        for (int i = 0; i < size; i++) {
            if (board[row][i] != player) rowWin = false;
            if (board[i][col] != player) colWin = false;
            if (board[i][i] != player) diagWin = false;
            if (board[i][size - 1 - i] != player) antiDiagWin = false;
        }

        if (rowWin || colWin || (row == col && diagWin) || (row + col == size - 1 && antiDiagWin)) {
            return player;
        }
        return 0;
    }
};
