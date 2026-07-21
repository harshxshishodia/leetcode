class Solution {
    int maximumLength;
    long long numberOfSequences;

    void solve(const vector<int>& nums, int index, int length) {
        if (length > maximumLength) {
            maximumLength = length;
            numberOfSequences = 1;
        } else if (length == maximumLength) {
            numberOfSequences++;
        }

        for (int nextIndex = index + 1; nextIndex < nums.size(); nextIndex++) {
            if (nums[nextIndex] > nums[index])
                solve(nums, nextIndex, length + 1);
        }
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        maximumLength = 0;
        numberOfSequences = 0;

        for (int index = 0; index < nums.size(); index++)
            solve(nums, index, 1);

        return numberOfSequences;
    }
};