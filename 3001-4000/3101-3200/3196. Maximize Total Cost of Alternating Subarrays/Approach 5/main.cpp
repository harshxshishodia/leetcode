class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        long long nextPlus = 0;
        long long nextMinus = 0;

        for (int index =
                 static_cast<int>(nums.size()) -
                 1;
             index >= 0;
             index--) {
            long long currentPlus =
                nums[index] +
                nextMinus;

            long long currentMinus = max(
                -1LL *
                    nums[index] +
                    nextPlus,
                nums[index] +
                    nextMinus
            );

            nextPlus =
                currentPlus;

            nextMinus =
                currentMinus;
        }

        return nextPlus;
    }
};
