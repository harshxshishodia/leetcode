class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (const vector<int>& building : buildings) {
            events.push_back({building[0], -building[2]});
            events.push_back({building[1], building[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> activeHeights;
        activeHeights.insert(0);

        vector<vector<int>> answer;
        int previousHeight = 0;
        int index = 0;

        while (index < events.size()) {
            int coordinate = events[index].first;

            while (index < events.size() && events[index].first == coordinate) {
                int height = events[index].second;

                if (height < 0)
                    activeHeights.insert(-height);
                else
                    activeHeights.erase(activeHeights.find(height));

                index++;
            }

            int currentHeight = *activeHeights.rbegin();

            if (currentHeight != previousHeight) {
                answer.push_back({coordinate, currentHeight});
                previousHeight = currentHeight;
            }
        }

        return answer;
    }
};