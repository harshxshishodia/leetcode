class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(),
            intervals.end(),
            [](const vector<int>& first, const vector<int>& second) {
                if (first[0] != second[0]) {
                    return first[0] < second[0];
                }

                return first[1] < second[1];
            }
        );

        int removals = 0;
        int end = intervals[0][1];

        for (int i = 1; i < static_cast<int>(intervals.size()); i++) {
            if (intervals[i][0] < end) {
                removals++;
                end = min(end, intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }

        return removals;
    }
};
