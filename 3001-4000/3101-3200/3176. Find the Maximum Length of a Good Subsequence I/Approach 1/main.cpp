class Solution {
    int solve(
        const vector<int>& nums,
        int k,
        int index,
        int previous,
        int changes
    ) {
        if (index ==
            static_cast<int>(
                nums.size()
            )) {
            return 0;
        }

        int skip =
            solve(
                nums,
                k,
                index + 1,
                previous,
                changes
            );

        int take = 0;

        if (previous == -1) {
            take =
                1 +
                solve(
                    nums,
                    k,
                    index + 1,
                    index,
                    changes
                );
        } else {
            int nextChanges =
                changes +
                (
                    nums[index] !=
                    nums[previous]
                );

            if (nextChanges <= k) {
                take =
                    1 +
                    solve(
                        nums,
                        k,
                        index + 1,
                        index,
                        nextChanges
                    );
            }
        }

        return max(
            skip,
            take
        );
    }

public:
    int maximumLength(
        vector<int>& nums,
        int k
    ) {
        return solve(
            nums,
            k,
            0,
            -1,
            0
        );
    }
};
