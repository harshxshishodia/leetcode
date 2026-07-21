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
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int n = nums.size();
        int size = values.size();
        vector<int> answer(n, 0);
        tree.assign(size * 4, 0);

        for (int index = n - 1; index >= 0; index--) {
            int rank = lower_bound(values.begin(), values.end(), nums[index]) - values.begin();

            if (rank > 0)
                answer[index] = query(1, 0, size - 1, 0, rank - 1);

            update(1, 0, size - 1, rank);
        }

        return answer;
    }
};