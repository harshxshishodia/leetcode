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

    void update(int index, Node value) {
        while (index < tree.size()) {
            tree[index] = mergeNodes(tree[index], value);
            index += index & -index;
        }
    }

    Node query(int index) {
        Node result = {0, 0};

        while (index > 0) {
            result = mergeNodes(result, tree[index]);
            index -= index & -index;
        }

        return result;
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        tree.assign(values.size() + 1, {0, 0});

        for (int number : nums) {
            int rank = lower_bound(values.begin(), values.end(), number) - values.begin() + 1;
            Node previous = query(rank - 1);
            Node current = {previous.length + 1, previous.length == 0 ? 1 : previous.count};
            update(rank, current);
        }

        return query(values.size()).count;
    }
};