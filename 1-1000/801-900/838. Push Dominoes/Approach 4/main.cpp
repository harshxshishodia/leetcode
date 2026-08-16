class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = static_cast<int>(dominoes.size());
        vector<int> force(n);

        int value = 0;

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                value = n;
            } else if (dominoes[i] == 'L') {
                value = 0;
            } else {
                value = max(
                    value - 1,
                    0
                );
            }

            force[i] += value;
        }

        value = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                value = n;
            } else if (dominoes[i] == 'R') {
                value = 0;
            } else {
                value = max(
                    value - 1,
                    0
                );
            }

            force[i] -= value;
        }

        string answer = dominoes;

        for (int i = 0; i < n; i++) {
            if (force[i] > 0) {
                answer[i] = 'R';
            } else if (force[i] < 0) {
                answer[i] = 'L';
            } else {
                answer[i] = '.';
            }
        }

        return answer;
    }
};
