class Solution {
    int answer =
        numeric_limits<int>::max();

    void search(
        string& street,
        int index,
        int buckets
    ) {
        if (buckets >= answer) {
            return;
        }

        int n =
            static_cast<int>(street.size());

        while (index < n) {
            if (street[index] != 'H') {
                index++;
                continue;
            }

            bool fed =
                (
                    index > 0 &&
                    street[index - 1] == 'B'
                ) ||
                (
                    index + 1 < n &&
                    street[index + 1] == 'B'
                );

            if (fed) {
                index++;
                continue;
            }

            break;
        }

        if (index == n) {
            answer = min(
                answer,
                buckets
            );

            return;
        }

        bool placed = false;

        if (index + 1 < n &&
            street[index + 1] == '.') {
            placed = true;
            street[index + 1] = 'B';

            search(
                street,
                index + 1,
                buckets + 1
            );

            street[index + 1] = '.';
        }

        if (index > 0 &&
            street[index - 1] == '.') {
            placed = true;
            street[index - 1] = 'B';

            search(
                street,
                index + 1,
                buckets + 1
            );

            street[index - 1] = '.';
        }

        if (!placed) {
            return;
        }
    }

public:
    int minimumBuckets(string hamsters) {
        answer =
            numeric_limits<int>::max();

        search(
            hamsters,
            0,
            0
        );

        return answer ==
               numeric_limits<int>::max()
            ? -1
            : answer;
    }
};
