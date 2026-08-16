class Solution {
    bool valid(
        const string& hamsters,
        int mask,
        const vector<int>& dots
    ) {
        string street =
            hamsters;

        for (int index = 0;
             index < static_cast<int>(dots.size());
             index++) {
            if ((mask & (1 << index)) != 0) {
                street[dots[index]] =
                    'B';
            }
        }

        for (int index = 0;
             index < static_cast<int>(street.size());
             index++) {
            if (street[index] != 'H') {
                continue;
            }

            bool fed =
                (
                    index > 0 &&
                    street[index - 1] == 'B'
                ) ||
                (
                    index + 1 <
                    static_cast<int>(street.size()) &&
                    street[index + 1] == 'B'
                );

            if (!fed) {
                return false;
            }
        }

        return true;
    }

public:
    int minimumBuckets(string hamsters) {
        vector<int> dots;

        for (int index = 0;
             index < static_cast<int>(hamsters.size());
             index++) {
            if (hamsters[index] == '.') {
                dots.push_back(index);
            }
        }

        int answer =
            numeric_limits<int>::max();

        int states =
            1 << dots.size();

        for (int mask = 0; mask < states; mask++) {
            int count =
                __builtin_popcount(
                    static_cast<unsigned int>(mask)
                );

            if (count >= answer) {
                continue;
            }

            if (valid(
                    hamsters,
                    mask,
                    dots)) {
                answer = count;
            }
        }

        return answer ==
               numeric_limits<int>::max()
            ? -1
            : answer;
    }
};
