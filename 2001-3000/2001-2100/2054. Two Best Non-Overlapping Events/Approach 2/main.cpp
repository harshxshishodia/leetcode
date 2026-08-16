class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(
            events.begin(),
            events.end()
        );

        int n =
            static_cast<int>(events.size());

        vector<int> suffix(
            n + 1
        );

        for (int index = n - 1;
             index >= 0;
             index--) {
            suffix[index] = max(
                suffix[index + 1],
                events[index][2]
            );
        }

        int answer = 0;

        for (int index = 0; index < n; index++) {
            int next =
                upper_bound(
                    events.begin(),
                    events.end(),
                    events[index][1],
                    [](int value, const vector<int>& event) {
                        return value < event[0];
                    }
                ) -
                events.begin();

            answer = max(
                answer,
                events[index][2] +
                suffix[next]
            );
        }

        return answer;
    }
};
