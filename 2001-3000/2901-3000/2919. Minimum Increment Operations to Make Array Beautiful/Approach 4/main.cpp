class Solution {
public:
    long long minIncrementOperations(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        if (n < 3) {
            return 0;
        }

        vector<long long> choose(
            n
        );

        for (int index = 0;
             index < n;
             index++) {
            long long cost =
                max(
                    0,
                    k -
                    nums[index]
                );

            long long previous = 0;

            if (index >= 3) {
                previous = min({
                    choose[index - 1],
                    choose[index - 2],
                    choose[index - 3]
                });
            }

            choose[index] =
                cost +
                previous;
        }

        return min({
            choose[n - 1],
            choose[n - 2],
            choose[n - 3]
        });
    }
};
