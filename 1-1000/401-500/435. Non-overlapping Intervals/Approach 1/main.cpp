class Solution {
    int best;

    void search(
        const vector<vector<int>>& intervals,
        int index,
        vector<vector<int>>& chosen
    ) {
        if (index == static_cast<int>(intervals.size())) {
            for (int i = 0; i < static_cast<int>(chosen.size()); i++) {
                for (int j = i + 1; j < static_cast<int>(chosen.size()); j++) {
                    if (max(chosen[i][0], chosen[j][0]) <
                        min(chosen[i][1], chosen[j][1])) {
                        return;
                    }
                }
            }

            best = max(best, static_cast<int>(chosen.size()));
            return;
        }

        search(intervals, index + 1, chosen);

        chosen.push_back(intervals[index]);
        search(intervals, index + 1, chosen);
        chosen.pop_back();
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        best = 0;
        vector<vector<int>> chosen;
        search(intervals, 0, chosen);

        return static_cast<int>(intervals.size()) - best;
    }
};
