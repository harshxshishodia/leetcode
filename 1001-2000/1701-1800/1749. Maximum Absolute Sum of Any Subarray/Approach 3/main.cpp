class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefix = 0;
        int minimumPrefix = 0;
        int maximumPrefix = 0;

        for (int value : nums) {
            prefix += value;

            minimumPrefix = min(
                minimumPrefix,
                prefix
            );

            maximumPrefix = max(
                maximumPrefix,
                prefix
            );
        }

        return
            maximumPrefix -
            minimumPrefix;
    }
};
