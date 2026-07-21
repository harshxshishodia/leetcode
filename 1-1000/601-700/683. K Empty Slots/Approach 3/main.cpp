class Solution {
    vector<int> tree;

    void build(const vector<int>& days, int node, int left, int right) {
        if (left == right) {
            tree[node] = days[left];
            return;
        }

        int middle = left + (right - left) / 2;
        build(days, node * 2, left, middle);
        build(days, node * 2 + 1, middle + 1, right);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left)
            return INT_MAX;

        if (queryLeft <= left && right <= queryRight)
            return tree[node];

        int middle = left + (right - left) / 2;
        return min(query(node * 2, left, middle, queryLeft, queryRight), query(node * 2 + 1, middle + 1, right, queryLeft, queryRight));
    }

public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<int> days(n);

        for (int day = 0; day < n; day++)
            days[bulbs[day] - 1] = day + 1;

        tree.assign(4 * n, INT_MAX);
        build(days, 1, 0, n - 1);

        int answer = INT_MAX;

        for (int left = 0; left + k + 1 < n; left++) {
            int right = left + k + 1;
            int currentDay = max(days[left], days[right]);
            int minimumInside = query(1, 0, n - 1, left + 1, right - 1);

            if (minimumInside > currentDay)
                answer = min(answer, currentDay);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};