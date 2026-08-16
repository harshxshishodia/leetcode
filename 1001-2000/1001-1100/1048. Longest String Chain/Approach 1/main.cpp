class Solution {
    bool predecessor(
        const string& shorter,
        const string& longer
    ) {
        if (longer.size() != shorter.size() + 1) {
            return false;
        }

        int first = 0;
        int second = 0;
        int skipped = 0;

        while (second < static_cast<int>(longer.size())) {
            if (first < static_cast<int>(shorter.size()) &&
                shorter[first] == longer[second]) {
                first++;
                second++;
            } else {
                skipped++;
                second++;

                if (skipped > 1) {
                    return false;
                }
            }
        }

        return first ==
               static_cast<int>(shorter.size());
    }

    int solve(
        const vector<string>& words,
        int index,
        int previous
    ) {
        if (index == static_cast<int>(words.size())) {
            return 0;
        }

        int skip = solve(
            words,
            index + 1,
            previous
        );

        int take = 0;

        if (previous == -1 ||
            predecessor(
                words[previous],
                words[index]
            )) {
            take =
                1 +
                solve(
                    words,
                    index + 1,
                    index
                );
        }

        return max(
            skip,
            take
        );
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(
            words.begin(),
            words.end(),
            [](const string& first, const string& second) {
                return first.size() < second.size();
            }
        );

        return solve(
            words,
            0,
            -1
        );
    }
};
