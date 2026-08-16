class Solution {
public:
    int minimumBuckets(string hamsters) {
        int answer = 0;
        int n =
            static_cast<int>(hamsters.size());

        for (int index = 0; index < n; index++) {
            if (hamsters[index] != 'H') {
                continue;
            }

            if (index > 0 &&
                hamsters[index - 1] == 'B') {
                continue;
            }

            if (index + 1 < n &&
                hamsters[index + 1] == '.') {
                hamsters[index + 1] =
                    'B';

                answer++;
            } else if (index > 0 &&
                       hamsters[index - 1] == '.') {
                hamsters[index - 1] =
                    'B';

                answer++;
            } else {
                return -1;
            }
        }

        return answer;
    }
};
