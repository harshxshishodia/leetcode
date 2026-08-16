class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const long long MOD =
            1000000007;

        vector<int> ones;

        for (int index = 0;
             index < static_cast<int>(nums.size());
             index++) {
            if (nums[index] == 1) {
                ones.push_back(index);
            }
        }

        if (ones.empty()) {
            return 0;
        }

        long long answer = 1;

        for (int index = 1;
             index < static_cast<int>(ones.size());
             index++) {
            answer *=
                ones[index] -
                ones[index - 1];

            answer %=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
