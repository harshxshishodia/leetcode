class Solution {
public:
    string pushDominoes(string dominoes) {
        string extended =
            "L" +
            dominoes +
            "R";

        int previous = 0;

        for (int current = 1;
             current < static_cast<int>(extended.size());
             current++) {
            if (extended[current] == '.') {
                continue;
            }

            if (current - previous > 1) {
                char left =
                    extended[previous];

                char right =
                    extended[current];

                if (left == right) {
                    for (int i = previous + 1; i < current; i++) {
                        extended[i] = left;
                    }
                } else if (left == 'R' &&
                           right == 'L') {
                    int first =
                        previous + 1;

                    int second =
                        current - 1;

                    while (first < second) {
                        extended[first] = 'R';
                        extended[second] = 'L';
                        first++;
                        second--;
                    }
                }
            }

            previous = current;
        }

        return extended.substr(
            1,
            dominoes.size()
        );
    }
};
