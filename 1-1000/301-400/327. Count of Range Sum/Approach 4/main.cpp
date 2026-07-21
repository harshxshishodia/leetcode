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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int index = 0; index < n; index++)
            prefix[index + 1] = prefix[index] + nums[index];

        vector<long long> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int size = values.size();
        tree.assign(size * 4, 0);
        long long answer = 0;

        for (long long sum : prefix) {
            int leftIndex = lower_bound(values.begin(), values.end(), sum - upper) - values.begin();
            int rightIndex = upper_bound(values.begin(), values.end(), sum - lower) - values.begin() - 1;

            if (leftIndex <= rightIndex)
                answer += query(1, 0, size - 1, leftIndex, rightIndex);

            int rank = lower_bound(values.begin(), values.end(), sum) - values.begin();
            update(1, 0, size - 1, rank);
        }

        return answer;
    }
};