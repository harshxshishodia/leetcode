class Solution {
    bool solve(string& state, unordered_map<string, bool>& memo) {
        auto found = memo.find(state);

        if (found != memo.end()) {
            return found->second;
        }

        for (int i = 0; i + 1 < static_cast<int>(state.size()); i++) {
            if (state[i] != '+' || state[i + 1] != '+') {
                continue;
            }

            state[i] = '-';
            state[i + 1] = '-';

            bool opponentWins = solve(state, memo);

            state[i] = '+';
            state[i + 1] = '+';

            if (!opponentWins) {
                memo[state] = true;
                return true;
            }
        }

        memo[state] = false;
        return false;
    }

public:
    bool canWin(string currentState) {
        unordered_map<string, bool> memo;
        return solve(currentState, memo);
    }
};
