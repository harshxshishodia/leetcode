class Solution {
    vector<int> best;

    bool valid(const vector<int>& subset) {
        for (int i = 0; i < static_cast<int>(subset.size()); i++) {
            for (int j = i + 1; j < static_cast<int>(subset.size()); j++) {
                if (subset[j] % subset[i] != 0 &&
                    subset[i] % subset[j] != 0) {
                    return false;
                }
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
            if (current.size() > best.size() && valid(current)) {
                best = current;
            }

            return;
        }

        search(nums, index + 1, current);

        current.push_back(nums[index]);
        search(nums, index + 1, current);
        current.pop_back();
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        best.clear();
        vector<int> current;
        search(nums, 0, current);
        return best;
    }
};
