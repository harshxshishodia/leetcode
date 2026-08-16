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

        int selected = 0;
        int lastEnd = -1;

        for (auto [left, right] :
             intervals) {
            if (left > lastEnd) {
                selected++;
                lastEnd =
                    right;
            }
        }

        return selected >= k;
    }
};
