class Solution {
public:
    string pushDominoes(string dominoes) {
        string current = dominoes;
        int n = static_cast<int>(dominoes.size());

        while (true) {
            string next = current;
            bool changed = false;

            for (int i = 0; i < n; i++) {
                if (current[i] != '.') {
                    continue;
                }

                bool pushedRight =
                    i > 0 &&
                    current[i - 1] == 'R';

                bool pushedLeft =
                    i + 1 < n &&
                    current[i + 1] == 'L';

                if (pushedRight == pushedLeft) {
                    continue;
                }

                next[i] =
                    pushedRight
                        ? 'R'
                        : 'L';

                changed = true;
            }

            if (!changed) {
                return current;
            }

            current = next;
        }
    }
};
