class Solution {
    struct BestTwo {
        int firstValue = 0;
        int firstLength = 0;
        int secondValue = 0;
        int secondLength = 0;
        bool hasFirst = false;
        bool hasSecond = false;
    };

    void update(
        BestTwo& best,
        int value,
        int length
    ) {
        if (
            best.hasFirst &&
            best.firstValue == value
        ) {
            best.firstLength = max(
                best.firstLength,
                length
            );

            return;
        }

        if (
            best.hasSecond &&
            best.secondValue == value
        ) {
            best.secondLength = max(
                best.secondLength,
                length
            );

            if (
                best.secondLength >
                best.firstLength
            ) {
                swap(
                    best.firstValue,
                    best.secondValue
                );

                swap(
                    best.firstLength,
                    best.secondLength
                );
            }

            return;
        }

        if (
            !best.hasFirst ||
            length >
            best.firstLength
        ) {
            if (best.hasFirst) {
                best.hasSecond =
                    true;

                best.secondValue =
                    best.firstValue;

                best.secondLength =
                    best.firstLength;
            }

            best.hasFirst =
                true;

            best.firstValue =
                value;

            best.firstLength =
                length;
        } else if (
            !best.hasSecond ||
            length >
            best.secondLength
        ) {
            best.hasSecond =
                true;

            best.secondValue =
                value;

            best.secondLength =
                length;
        }
    }

    int bestOther(
        const BestTwo& best,
        int value
    ) {
        if (
            best.hasFirst &&
            best.firstValue != value
        ) {
            return
                best.firstLength;
        }

        if (
            best.hasSecond &&
            best.secondValue != value
        ) {
            return
                best.secondLength;
        }

        return 0;
    }

public:
    int maximumLength(
        vector<int>& nums,
        int k
    ) {
        unordered_map<
            int,
            vector<int>
        > ending;

        vector<BestTwo> best(
            k + 1
        );

        int answer = 0;

        for (int value :
             nums) {
            vector<int>& current =
                ending[value];

            if (current.empty()) {
                current.assign(
                    k + 1,
                    0
                );
            }

            vector<int> next =
                current;

            for (int changes = 0;
                 changes <= k;
                 changes++) {
                next[changes] = max(
                    next[changes],
                    current[changes] +
                    1
                );

                if (changes > 0) {
                    int other =
                        bestOther(
                            best[changes - 1],
                            value
                        );

                    if (other > 0) {
                        next[changes] = max(
                            next[changes],
                            other +
                            1
                        );
                    }
                }

                next[changes] = max(
                    next[changes],
                    1
                );
            }

            current =
                next;

            for (int changes = 0;
                 changes <= k;
                 changes++) {
                update(
                    best[changes],
                    value,
                    current[changes]
                );

                answer = max(
                    answer,
                    current[changes]
                );
            }
        }

        return answer;
    }
};
