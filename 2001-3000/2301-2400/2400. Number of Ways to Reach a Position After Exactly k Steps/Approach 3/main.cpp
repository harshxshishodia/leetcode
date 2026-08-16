class Solution {
public:
    int numberOfWays(
        int startPos,
        int endPos,
        int k
    ) {
        const int MOD =
            1000000007;

        int width =
            2 *
            k +
            1;

        int offset =
            k;

        vector<int> previous(
            width
        );

        previous[offset] = 1;

        for (int step = 1;
             step <= k;
             step++) {
            vector<int> current(
                width
            );

            for (int position = 0;
                 position < width;
                 position++) {
                if (previous[position] == 0) {
                    continue;
                }

                if (position > 0) {
                    current[position - 1] =
                        (
                            current[position - 1] +
                            previous[position]
                        ) %
                        MOD;
                }

                if (position + 1 < width) {
                    current[position + 1] =
                        (
                            current[position + 1] +
                            previous[position]
                        ) %
                        MOD;
                }
            }

            previous = current;
        }

        int delta =
            endPos -
            startPos;

        int targetIndex =
            offset +
            delta;

        if (targetIndex < 0 ||
            targetIndex >= width) {
            return 0;
        }

        return previous[targetIndex];
    }
};
