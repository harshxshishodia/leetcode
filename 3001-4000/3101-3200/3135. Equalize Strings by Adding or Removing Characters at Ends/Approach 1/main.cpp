class Solution {
public:
    int minOperations(
        string initial,
        string target
    ) {
        int best = 0;

        for (int firstLeft = 0;
             firstLeft < static_cast<int>(initial.size());
             firstLeft++) {
            for (int firstRight = firstLeft;
                 firstRight < static_cast<int>(initial.size());
                 firstRight++) {
                int length =
                    firstRight -
                    firstLeft +
                    1;

                for (int secondLeft = 0;
                     secondLeft +
                     length <=
                     static_cast<int>(target.size());
                     secondLeft++) {
                    bool equal =
                        true;

                    for (int offset = 0;
                         offset < length;
                         offset++) {
                        if (
                            initial[
                                firstLeft +
                                offset
                            ] !=
                            target[
                                secondLeft +
                                offset
                            ]
                        ) {
                            equal =
                                false;

                            break;
                        }
                    }

                    if (equal) {
                        best = max(
                            best,
                            length
                        );
                    }
                }
            }
        }

        return
            static_cast<int>(
                initial.size() +
                target.size()
            ) -
            2 *
            best;
    }
};
