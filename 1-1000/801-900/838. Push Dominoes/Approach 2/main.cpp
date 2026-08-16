class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = static_cast<int>(dominoes.size());

        vector<int> rightForce(
            n,
            n
        );

        vector<int> leftForce(
            n,
            n
        );

        int distance = n;

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                distance = 0;
            } else if (dominoes[i] == 'L') {
                distance = n;
            } else if (distance < n) {
                distance++;
            }

            rightForce[i] = distance;
        }

        distance = n;

        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                distance = 0;
            } else if (dominoes[i] == 'R') {
                distance = n;
            } else if (distance < n) {
                distance++;
            }

            leftForce[i] = distance;
        }

        string answer = dominoes;

        for (int i = 0; i < n; i++) {
            if (rightForce[i] < leftForce[i]) {
                answer[i] = 'R';
            } else if (leftForce[i] < rightForce[i]) {
                answer[i] = 'L';
            } else {
                answer[i] = '.';
            }
        }

        return answer;
    }
};
