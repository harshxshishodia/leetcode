class Solution {
    vector<int> tree;

    void update(int node, int left, int right, int queryLeft, int queryRight, int height) {
        if (queryRight < left || right < queryLeft)
            return;

        if (queryLeft <= left && right <= queryRight) {
            tree[node] = max(tree[node], height);
            return;
        }

        int middle = left + (right - left) / 2;
        update(node * 2, left, middle, queryLeft, queryRight, height);
        update(node * 2 + 1, middle + 1, right, queryLeft, queryRight, height);
    }

    int query(int node, int left, int right, int index, int maximumHeight) {
        maximumHeight = max(maximumHeight, tree[node]);

        if (left == right)
            return maximumHeight;

        int middle = left + (right - left) / 2;

        if (index <= middle)
            return query(node * 2, left, middle, index, maximumHeight);

        return query(node * 2 + 1, middle + 1, right, index, maximumHeight);
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

        int segmentCount = coordinates.size() - 1;
        tree.assign(segmentCount * 4, 0);

        for (const vector<int>& building : buildings) {
            int left = lower_bound(coordinates.begin(), coordinates.end(), building[0]) - coordinates.begin();
            int right = lower_bound(coordinates.begin(), coordinates.end(), building[1]) - coordinates.begin() - 1;
            update(1, 0, segmentCount - 1, left, right, building[2]);
        }

        vector<vector<int>> answer;
        int previousHeight = 0;

        for (int index = 0; index < segmentCount; index++) {
            int currentHeight = query(1, 0, segmentCount - 1, index, 0);

            if (currentHeight != previousHeight) {
                answer.push_back({coordinates[index], currentHeight});
                previousHeight = currentHeight;
            }
        }

        answer.push_back({coordinates.back(), 0});
        return answer;
    }
};