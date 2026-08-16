class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flips = 0;

        for (int value : nums) {
            int effective =
                value ^
                (flips & 1);

            if (effective == 0) {
                flips++;
            }
        }

        return flips;
    }
};
