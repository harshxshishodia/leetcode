class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long add = 0;
        long long subtract = 0;

        for (int index = static_cast<int>(nums.size()) - 1;
             index >= 0;
             index--) {
            long long nextAdd = max(
                add,
                nums[index] + subtract
            );

            long long nextSubtract = max(
                subtract,
                -nums[index] + add
            );

            add = nextAdd;
            subtract = nextSubtract;
        }

        return add;
    }
};
