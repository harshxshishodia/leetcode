class Solution {
    bool matches(char patternCharacter, char stringCharacter) {
        return patternCharacter == '.' || patternCharacter == stringCharacter;
    }

    vector<int> closure(const string& p, const vector<int>& states) {
        int n = p.size();
        vector<bool> visited(n + 1, false);
        queue<int> pending;

        for (int state : states) {
            if (!visited[state]) {
                visited[state] = true;
                pending.push(state);
            }
        }

        while (!pending.empty()) {
            int state = pending.front();
            pending.pop();

            if (state + 1 < n && p[state + 1] == '*' && !visited[state + 2]) {
                visited[state + 2] = true;
                pending.push(state + 2);
            }
        }

        vector<int> result;

        for (int state = 0; state <= n; state++) {
            if (visited[state])
                result.push_back(state);
        }

        return result;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.size();
        vector<int> states = closure(p, {0});

        for (char character : s) {
            vector<int> nextStates;
            vector<bool> added(n + 1, false);

            for (int state : states) {
                if (state == n)
                    continue;

                if (state + 1 < n && p[state + 1] == '*') {
                    if (matches(p[state], character) && !added[state]) {
                        added[state] = true;
                        nextStates.push_back(state);
                    }
                } else {
                    if (matches(p[state], character) && !added[state + 1]) {
                        added[state + 1] = true;
                        nextStates.push_back(state + 1);
                    }
                }
            }

            states = closure(p, nextStates);
        }

        for (int state : states) {
            if (state == n)
                return true;
        }

        return false;
    }
};