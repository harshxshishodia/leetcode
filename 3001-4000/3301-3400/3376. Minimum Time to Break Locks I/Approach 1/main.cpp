class Solution {
public:
    int findMinimumTime(
        vector<int>& strength,
        int K
    ) {
        sort(
            strength.begin(),
            strength.end()
        );

        int answer =
            numeric_limits<int>::max();

        do {
            int time = 0;

            for (int index = 0;
                 index < static_cast<int>(strength.size());
                 index++) {
                int factor =
                    1 +
                    index *
                    K;

                time +=
                    (
                        strength[index] +
                        factor -
                        1
                    ) /
                    factor;
            }

            answer = min(
                answer,
                time
            );
        } while (
            next_permutation(
                strength.begin(),
                strength.end()
            )
        );

        return answer;
    }
};
