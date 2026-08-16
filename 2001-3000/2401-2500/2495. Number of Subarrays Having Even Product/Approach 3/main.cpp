class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long n =
            nums.size();

        long long total =
            n *
            (n + 1) /
            2;

        long long oddOnly = 0;
        long long run = 0;

        for (int value : nums) {
            if (value % 2 != 0) {
                run++;
            } else {
                oddOnly +=
                    run *
                    (run + 1) /
                    2;

                run = 0;
            }
        }

        oddOnly +=
            run *
            (run + 1) /
            2;

        return
            total -
            oddOnly;
    }
};
