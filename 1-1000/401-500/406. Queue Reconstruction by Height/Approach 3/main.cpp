class Solution {
    vector<int> tree;

    void update(int index, int value) {
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int findPosition(int order) {
        int index = 0;
        int bit = 1;

        while ((bit << 1) < tree.size())
            bit <<= 1;

        while (bit > 0) {
            int nextIndex = index + bit;

            if (nextIndex < tree.size() && tree[nextIndex] < order) {
                index = nextIndex;
                order -= tree[nextIndex];
            }

            bit >>= 1;
        }

        return index;
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();

        sort(people.begin(), people.end(), [](const vector<int>& first, const vector<int>& second) {
            if (first[0] == second[0])
                return first[1] > second[1];

            return first[0] < second[0];
        });

        tree.assign(n + 1, 0);

        for (int index = 1; index <= n; index++)
            update(index, 1);

        vector<vector<int>> answer(n);

        for (const vector<int>& person : people) {
            int position = findPosition(person[1] + 1);
            answer[position] = person;
            update(position + 1, -1);
        }

        return answer;
    }
};