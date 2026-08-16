class Solution {
    int best = 0;

    bool wiggles(const vector<int>& sequence) {
        if (sequence.size() <= 1) {
            return true;
        }

        long long previousDifference = 0;

        for (int i = 1; i < static_cast<int>(sequence.size()); i++) {
            long long difference =
                static_cast<long long>(sequence[i]) -
                sequence[i - 1];

            if (difference == 0) {
                return false;
            }

            if (previousDifference != 0 &&
                ((difference > 0) == (previousDifference > 0))) {
                return false;
            }

            previousDifference = difference;
        }

        return true;
    }

    void search(
        const vector<int>& nums,
        int index,
        vector<int>& current
    ) {
        if (index == static_cast<int>(nums.size())) {
            if (wiggles(current)) {
                best = max(best, static_cast<int>(current.size()));
            }

            return;
        }

        search(nums, index + 1, current);

        current.push_back(nums[index]);
        search(nums, index + 1, current);
        current.pop_back();
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        best = 0;
        vector<int> current;
        search(nums, 0, current);
        return best;
    }
};
