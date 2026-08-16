class Solution {
    vector<pair<int, int>> buildIntervals(
        const string& s
    ) {
        int n =
            static_cast<int>(s.size());

        array<int, 26> first;
        array<int, 26> last;

        first.fill(n);
        last.fill(-1);

        for (int index = 0;
             index < n;
             index++) {
            int character =
                s[index] -
                'a';

            first[character] = min(
                first[character],
                index
            );

            last[character] =
                index;
        }

        vector<pair<int, int>> intervals;

        for (int character = 0;
             character < 26;
             character++) {
            if (last[character] == -1) {
                continue;
            }

            int left =
                first[character];

            int right =
                last[character];

            bool valid =
                true;

            for (int index = left;
                 index <= right;
                 index++) {
                int current =
                    s[index] -
                    'a';

                if (first[current] < left) {
                    valid =
                        false;

                    break;
                }

                right = max(
                    right,
                    last[current]
                );
            }

            if (
                valid &&
                !(
                    left == 0 &&
                    right == n - 1
                )
            ) {
                intervals.push_back({
                    left,
                    right
                });
            }
        }

        sort(
            intervals.begin(),
            intervals.end()
        );

        intervals.erase(
            unique(
                intervals.begin(),
                intervals.end()
            ),
            intervals.end()
        );

        return intervals;
    }

public:
    bool maxSubstringLength(
        string s,
        int k
    ) {
        if (k == 0) {
            return true;
        }

        vector<pair<int, int>> intervals =
            buildIntervals(s);

        sort(
            intervals.begin(),
            intervals.end(),
            [](const auto& firstInterval, const auto& secondInterval) {
                if (
                    firstInterval.second !=
                    secondInterval.second
                ) {
                    return
                        firstInterval.second <
                        secondInterval.second;
                }

                return
                    firstInterval.first <
                    secondInterval.first;
            }
        );

        int count =
            static_cast<int>(intervals.size());

        vector<int> dp(
            count + 1
        );

        vector<int> ends(count);

        for (int index = 0;
             index < count;
             index++) {
            ends[index] =
                intervals[index].second;
        }

        for (int index = 1;
             index <= count;
             index++) {
            int previous =
                lower_bound(
                    ends.begin(),
                    ends.begin() +
                    index -
                    1,
                    intervals[index - 1].first
                ) -
                ends.begin();

            dp[index] = max(
                dp[index - 1],
                1 +
                dp[previous]
            );
        }

        return dp[count] >= k;
    }
};
