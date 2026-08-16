class Solution {
public:
    bool maxSubstringLength(
        string s,
        int k
    ) {
        if (k == 0) {
            return true;
        }

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

        for (int left = 0;
             left < n;
             left++) {
            for (int right = left;
                 right < n;
                 right++) {
                if (
                    left == 0 &&
                    right == n - 1
                ) {
                    continue;
                }

                bool valid =
                    true;

                for (int index = left;
                     index <= right;
                     index++) {
                    int character =
                        s[index] -
                        'a';

                    if (
                        first[character] < left ||
                        last[character] > right
                    ) {
                        valid =
                            false;

                        break;
                    }
                }

                if (valid) {
                    intervals.push_back({
                        left,
                        right
                    });
                }
            }
        }

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
