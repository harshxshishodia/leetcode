class Solution {
    vector<int> parent;

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> coordinates;

        for (const vector<int>& building : buildings) {
            coordinates.push_back(building[0]);
            coordinates.push_back(building[1]);
        }

        sort(coordinates.begin(), coordinates.end());
        coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());

        sort(buildings.begin(), buildings.end(), [](const vector<int>& first, const vector<int>& second) {
            return first[2] > second[2];
        });

        int segmentCount = coordinates.size() - 1;
        vector<int> heights(segmentCount, 0);
        parent.resize(segmentCount + 1);

        for (int index = 0; index <= segmentCount; index++)
            parent[index] = index;

        for (const vector<int>& building : buildings) {
            int left = lower_bound(coordinates.begin(), coordinates.end(), building[0]) - coordinates.begin();
            int right = lower_bound(coordinates.begin(), coordinates.end(), building[1]) - coordinates.begin();
            int index = findParent(left);

            while (index < right) {
                heights[index] = building[2];
                parent[index] = findParent(index + 1);
                index = findParent(index);
            }
        }

        vector<vector<int>> answer;
        int previousHeight = 0;

        for (int index = 0; index < segmentCount; index++) {
            if (heights[index] != previousHeight) {
                answer.push_back({coordinates[index], heights[index]});
                previousHeight = heights[index];
            }
        }

        answer.push_back({coordinates.back(), 0});
        return answer;
    }
};