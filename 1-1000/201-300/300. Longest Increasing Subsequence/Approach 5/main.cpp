class Solution {
    struct Fenwick {
        vector<int> tree;

        Fenwick(int size) : tree(size + 1) {}

        void update(int index, int value) {
            while (index < static_cast<int>(tree.size())) {
                tree[index] = max(tree[index], value);
                index += index & -index;
            }
        }

        int query(int index) {
            int answer = 0;

            while (index > 0) {
                answer = max(answer, tree[index]);
                index -= index & -index;
            }

            return answer;
        }
    };

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        Fenwick fenwick(values.size());
        int answer = 0;

        for (int number : nums) {
            int rank = static_cast<int>(
                lower_bound(values.begin(), values.end(), number) -
                values.begin()
            ) + 1;

            int current = 1 + fenwick.query(rank - 1);
            fenwick.update(rank, current);
            answer = max(answer, current);
        }

        return answer;
    }
};
