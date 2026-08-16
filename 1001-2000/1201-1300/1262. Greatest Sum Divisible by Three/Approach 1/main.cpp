class Solution {
    int best = 0;

    void search(
        const vector<int>& nums,
        int index,
        int sum
    ) {
        if (index == static_cast<int>(nums.size())) {
            if (sum % 3 == 0) {
                best = max(
                    best,
                    sum
                );
            }

            return;
        }

        search(
            nums,
            index + 1,
            sum
        );

        search(
            nums,
            index + 1,
            sum + nums[index]
        );
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        best = 0;

        search(
            nums,
            0,
            0
        );

        return best;
    }
};
