class Solution {
    int bestLength;
    int count;

    bool increasing(const vector<int>& sequence) {
        for (int i = 1; i < static_cast<int>(sequence.size()); i++) {
            if (sequence[i] <= sequence[i - 1]) {
                return false;
            }
        }

        return true;
    }

    void search(
        const vector<int>& nums,
        int index,
        vector<int>& current
    ) {
        if (index == static_cast<int>(nums.size())) {
            if (!increasing(current)) {
                return;
            }

            int length = static_cast<int>(current.size());

            if (length > bestLength) {
                bestLength = length;
                count = 1;
            } else if (length == bestLength) {
                count++;
            }

            return;
        }

        search(
            nums,
            index + 1,
            current
        );

        current.push_back(nums[index]);

        search(
            nums,
            index + 1,
            current
        );

        current.pop_back();
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        bestLength = 0;
        count = 0;
        vector<int> current;

        search(
            nums,
            0,
            current
        );

        return count;
    }
};
