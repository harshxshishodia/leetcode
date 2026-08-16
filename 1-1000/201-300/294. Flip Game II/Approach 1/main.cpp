class Solution {
    bool solve(string& state) {
        for (int i = 0; i + 1 < static_cast<int>(state.size()); i++) {
            if (state[i] != '+' || state[i + 1] != '+') {
                continue;
            }

            state[i] = '-';
            state[i + 1] = '-';

            bool opponentWins = solve(state);

            state[i] = '+';
            state[i + 1] = '+';

            if (!opponentWins) {
                return true;
            }
        }

        return false;
    }

public:
    bool canWin(string currentState) {
        return solve(currentState);
    }
};
