class Solution {
    vector<int> tree;

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = 1;
            return;
        }

        int middle = left + (right - left) / 2;
        build(node * 2, left, middle);
        build(node * 2 + 1, middle + 1, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int findPosition(int node, int left, int right, int order) {
        if (left == right)
            return left;

        int middle = left + (right - left) / 2;

        if (tree[node * 2] >= order)
            return findPosition(node * 2, left, middle, order);

        return findPosition(node * 2 + 1, middle + 1, right, order - tree[node * 2]);
    }

    void removePosition(int node, int left, int right, int index) {
        if (left == right) {
            tree[node] = 0;
            return;
        }

        int middle = left + (right - left) / 2;

        if (index <= middle)
            removePosition(node * 2, left, middle, index);
        else
            removePosition(node * 2 + 1, middle + 1, right, index);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();

        sort(people.begin(), people.end(), [](const vector<int>& first, const vector<int>& second) {
            if (first[0] == second[0])
                return first[1] > second[1];

            return first[0] < second[0];
        });

        tree.assign(4 * n, 0);
        build(1, 0, n - 1);

        vector<vector<int>> answer(n);

        for (const vector<int>& person : people) {
            int position = findPosition(1, 0, n - 1, person[1] + 1);
            answer[position] = person;
            removePosition(1, 0, n - 1, position);
        }

        return answer;
    }
};