class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        const int INF =
            1000000000;

        array<int, 26> previous;

        previous.fill(
            INF
        );

        for (int current = 0;
             current < 26;
             current++) {
            previous[current] =
                word[0] -
                'a' !=
                current;
        }

        for (int index = 1;
             index < static_cast<int>(word.size());
             index++) {
            array<int, 26> current;

            current.fill(
                INF
            );

            for (int next = 0;
                 next < 26;
                 next++) {
                int change =
                    word[index] -
                    'a' !=
                    next;

                for (int last = 0;
                     last < 26;
                     last++) {
                    if (abs(
                            next -
                            last
                        ) <= 1) {
                        continue;
                    }

                    current[next] = min(
                        current[next],
                        previous[last] +
                        change
                    );
                }
            }

            previous =
                current;
        }

        return *min_element(
            previous.begin(),
            previous.end()
        );
    }
};
