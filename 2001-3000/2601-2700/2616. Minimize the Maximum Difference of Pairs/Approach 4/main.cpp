class Solution {
    bool possible(
        const vector<int>& nums,
        int p,
        int limit
    ) {
        int pairs = 0;

        for (int index = 1;
             index < static_cast<int>(nums.size());
             index++) {
            if (nums[index] -
                    nums[index - 1] <=
                limit) {
                pairs++;
                index++;

                if (pairs >= p) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    int minimizeMax(
        vector<int>& nums,
        int p
    ) {
        if (p == 0) {
            return 0;
        }

        sort(
            nums.begin(),
            nums.end()
        );

        int left = 0;

        int right =
            nums.back() -
            nums.front();

        while (left < right) {
            int middle =
                left +
                (right - left) /
                2;

            if (possible(
                    nums,
                    p,
                    middle)) {
                right =
                    middle;
            } else {
                left =
                    middle + 1;
            }
        }

        return left;
    }
};
