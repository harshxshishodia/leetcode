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
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int index = 0; index < n; index++)
            prefix[index + 1] = prefix[index] + nums[index];

        vector<long long> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        tree.assign(values.size() + 1, 0);
        long long answer = 0;

        for (long long sum : prefix) {
            int rightIndex = upper_bound(values.begin(), values.end(), sum - lower) - values.begin();
            int leftIndex = lower_bound(values.begin(), values.end(), sum - upper) - values.begin();
            answer += query(rightIndex) - query(leftIndex);

            int rank = lower_bound(values.begin(), values.end(), sum) - values.begin() + 1;
            update(rank);
        }

        return answer;
    }
};