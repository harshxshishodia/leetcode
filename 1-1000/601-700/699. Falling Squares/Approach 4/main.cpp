class Solution {
    vector<int> tree;
    vector<int> lazy;

    void push(int node) {
        if (lazy[node] == 0)
            return;

        tree[node * 2] = lazy[node];
        tree[node * 2 + 1] = lazy[node];
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
        lazy[node] = 0;
    }

    void update(int node, int left, int right, int queryLeft, int queryRight, int height) {
        if (queryLeft > right || queryRight < left)
            return;

        if (queryLeft <= left && right <= queryRight) {
            tree[node] = height;
            lazy[node] = height;
            return;
        }

        push(node);

        int middle = left + (right - left) / 2;
        update(node * 2, left, middle, queryLeft, queryRight, height);
        update(node * 2 + 1, middle + 1, right, queryLeft, queryRight, height);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left)
            return 0;

        if (queryLeft <= left && right <= queryRight)
            return tree[node];

        push(node);

        int middle = left + (right - left) / 2;
        return max(query(node * 2, left, middle, queryLeft, queryRight), query(node * 2 + 1, middle + 1, right, queryLeft, queryRight));
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> coordinates;

        for (const vector<int>& position : positions) {
            coordinates.push_back(position[0]);
            coordinates.push_back(position[0] + position[1]);
        }

        sort(coordinates.begin(), coordinates.end());
        coordinates.erase(unique(coordinates.begin(), coordinates.end()), coordinates.end());

        int segmentCount = coordinates.size() - 1;
        tree.assign(segmentCount * 4, 0);
        lazy.assign(segmentCount * 4, 0);

        vector<int> answer;
        int maximumHeight = 0;

        for (const vector<int>& position : positions) {
            int left = lower_bound(coordinates.begin(), coordinates.end(), position[0]) - coordinates.begin();
            int right = lower_bound(coordinates.begin(), coordinates.end(), position[0] + position[1]) - coordinates.begin() - 1;
            int baseHeight = query(1, 0, segmentCount - 1, left, right);
            int currentHeight = baseHeight + position[1];

            update(1, 0, segmentCount - 1, left, right, currentHeight);

            maximumHeight = max(maximumHeight, currentHeight);
            answer.push_back(maximumHeight);
        }

        return answer;
    }
};