class Solution {
public:
    int minOperations(
        string initial,
        string target
    ) {
        if (target.size() >
            initial.size()) {
            swap(
                initial,
                target
            );
        }

        int firstLength =
            static_cast<int>(
                initial.size()
            );

        int secondLength =
            static_cast<int>(
                target.size()
            );

        vector<int> previous(
            secondLength + 1
        );

        vector<int> current(
            secondLength + 1
        );

        int best = 0;

        for (int first = 1;
             first <= firstLength;
             first++) {
            fill(
                current.begin(),
                current.end(),
                0
            );

            for (int second = 1;
                 second <= secondLength;
                 second++) {
                if (
                    initial[first - 1] ==
                    target[second - 1]
                ) {
                    current[second] =
                        previous[second - 1] +
                        1;

                    best = max(
                        best,
                        current[second]
                    );
                }
            }

            previous.swap(
                current
            );
        }

        return
            firstLength +
            secondLength -
            2 *
            best;
    }
};
