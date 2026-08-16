class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> longest(
            n,
            1
        );

        int best = 0;

        for (int index = 0; index < n; index++) {
            for (int previous = 0; previous < index; previous++) {
                if (nums[previous] <= nums[index]) {
                    longest[index] = max(
                        longest[index],
                        longest[previous] + 1
                    );
                }
            }

            best = max(
                best,
                longest[index]
            );
        }

        return
            n -
            best;
    }
};
