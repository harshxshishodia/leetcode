class Solution {
    struct Node {
        int length;
        long long count;
    };

    vector<Node> tree;

    Node mergeNodes(const Node& first, const Node& second) {
        if (first.length > second.length)
            return first;

        if (second.length > first.length)
            return second;

        return {first.length, first.count + second.count};
    }

    void update(int node, int left, int right, int index, Node value) {
        if (left == right) {
            tree[node] = mergeNodes(tree[node], value);
            return;
        }

        int middle = left + (right - left) / 2;

        if (index <= middle)
            update(node * 2, left, middle, index, value);
        else
            update(node * 2 + 1, middle + 1, right, index, value);

        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left)
            return {0, 0};

        if (queryLeft <= left && right <= queryRight)
            return tree[node];

        int middle = left + (right - left) / 2;
        Node leftResult = query(node * 2, left, middle, queryLeft, queryRight);
        Node rightResult = query(node * 2 + 1, middle + 1, right, queryLeft, queryRight);
        return mergeNodes(leftResult, rightResult);
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int size = values.size();
        tree.assign(size * 4, {0, 0});

        for (int number : nums) {
            int rank = lower_bound(values.begin(), values.end(), number) - values.begin();
            Node previous = {0, 0};

            if (rank > 0)
                previous = query(1, 0, size - 1, 0, rank - 1);

            Node current = {previous.length + 1, previous.length == 0 ? 1 : previous.count};
            update(1, 0, size - 1, rank, current);
        }

        return tree[1].count;
    }
};