class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int>& first, const vector<int>& second) {
                return first[1] < second[1];
            }
        );

        int kept = 0;
        int end = numeric_limits<int>::min();

        for (const vector<int>& interval : intervals) {
            if (interval[0] >= end) {
                kept++;
                end = interval[1];
            }
        }

        return static_cast<int>(intervals.size()) - kept;
    }
};
