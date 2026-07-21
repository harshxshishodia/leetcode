class Solution {
    vector<int> tree;

    void update(int index) {
        while (index < tree.size()) {
            tree[index]++;
            index += index & -index;
        }
    }

    int query(int index) {
        int count = 0;

        while (index > 0) {
            count += tree[index];
            index -= index & -index;
        }

        return count;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int n = nums.size();
        vector<int> answer(n, 0);
        tree.assign(values.size() + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int rank = lower_bound(values.begin(), values.end(), nums[index]) - values.begin() + 1;
            answer[index] = query(rank - 1);
            update(rank);
        }

        return answer;
    }
};