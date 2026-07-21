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
    int reversePairs(vector<int>& nums) {
        vector<long long> values(nums.begin(), nums.end());
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        tree.assign(values.size() + 1, 0);

        int answer = 0;
        int inserted = 0;

        for (int number : nums) {
            int lessOrEqual = upper_bound(values.begin(), values.end(), 2LL * number) - values.begin();
            answer += inserted - query(lessOrEqual);

            int rank = lower_bound(values.begin(), values.end(), number) - values.begin() + 1;
            update(rank);
            inserted++;
        }

        return answer;
    }
};