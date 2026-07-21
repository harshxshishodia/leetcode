class Solution {
    vector<int> tree;

    void update(int node, int left, int right, int index) {
        if (left == right) {
            tree[node]++;
            return;
        }

        int middle = left + (right - left) / 2;

        if (index <= middle)
            update(node * 2, left, middle, index);
        else
            update(node * 2 + 1, middle + 1, right, index);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left)
            return 0;

        if (queryLeft <= left && right <= queryRight)
            return tree[node];

        int middle = left + (right - left) / 2;
        return query(node * 2, left, middle, queryLeft, queryRight) + query(node * 2 + 1, middle + 1, right, queryLeft, queryRight);
    }

public:
    int reversePairs(vector<int>& nums) {
        vector<long long> values(nums.begin(), nums.end());
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int size = values.size();
        int answer = 0;
        tree.assign(size * 4, 0);

        for (int number : nums) {
            int firstGreater = upper_bound(values.begin(), values.end(), 2LL * number) - values.begin();

            if (firstGreater < size)
                answer += query(1, 0, size - 1, firstGreater, size - 1);

            int rank = lower_bound(values.begin(), values.end(), number) - values.begin();
            update(1, 0, size - 1, rank);
        }

        return answer;
    }
};