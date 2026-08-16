class Solution {
    bool special(
        const string& s,
        int left,
        int right
    ) {
        if (
            left == 0 &&
            right ==
                static_cast<int>(s.size()) -
                1
        ) {
            return false;
        }

        array<bool, 26> inside = {};

        for (int index = left;
             index <= right;
             index++) {
            inside[
                s[index] -
                'a'
            ] =
                true;
        }

        for (int index = 0;
             index < static_cast<int>(s.size());
             index++) {
            if (
                (
                    index < left ||
                    index > right
                ) &&
                inside[
                    s[index] -
                    'a'
                ]
            ) {
                return false;
            }
        }

        return true;
    }

    bool choose(
        const vector<pair<int, int>>& intervals,
        int index,
        int lastEnd,
        int remaining
    ) {
        if (remaining == 0) {
            return true;
        }

        if (index ==
            static_cast<int>(intervals.size())) {
            return false;
        }

        if (choose(
                intervals,
                index + 1,
                lastEnd,
                remaining)) {
            return true;
        }

        if (
            intervals[index].first >
            lastEnd
        ) {
            if (choose(
                    intervals,
                    index + 1,
                    intervals[index].second,
                    remaining - 1)) {
                return true;
            }
        }

        return false;
    }

public:
    bool maxSubstringLength(
        string s,
        int k
    ) {
        if (k == 0) {
            return true;
        }

        vector<pair<int, int>> intervals;

        int n =
            static_cast<int>(s.size());

        for (int left = 0;
             left < n;
             left++) {
            for (int right = left;
                 right < n;
                 right++) {
                if (special(
                        s,
                        left,
                        right)) {
                    intervals.push_back({
                        left,
                        right
                    });
                }
            }
        }

        sort(
            intervals.begin(),
            intervals.end()
        );

        return choose(
            intervals,
            0,
            -1,
            k
        );
    }
};
