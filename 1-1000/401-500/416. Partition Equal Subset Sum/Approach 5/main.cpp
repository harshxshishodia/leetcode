class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;
        bitset<20001> possible;
        possible[0] = 1;

        for (int number : nums) {
            possible |= possible << number;
        }

        return possible[target];
    }
};
