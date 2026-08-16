class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int number : nums) {
            auto position = lower_bound(
                tails.begin(),
                tails.end(),
                number
            );

            if (position == tails.end()) {
                tails.push_back(number);
            } else {
                *position = number;
            }
        }

        return static_cast<int>(tails.size());
    }
};
