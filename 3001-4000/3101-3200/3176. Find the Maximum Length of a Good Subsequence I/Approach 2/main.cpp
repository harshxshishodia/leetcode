class Solution {
    vector<vector<vector<int>>> memo;
    vector<vector<vector<bool>>> visited;

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

        int previousState =
            previous +
            1;

        if (
            visited[index][previousState][changes]
        ) {
            return
                memo[index][previousState][changes];
        }

        visited[index][previousState][changes] =
            true;

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

        memo[index][previousState][changes] =
            max(
                skip,
                take
            );

        return
            memo[index][previousState][changes];
    }

public:
    int maximumLength(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(
                nums.size()
            );

        memo.assign(
            n,
            vector<vector<int>>(
                n + 1,
                vector<int>(
                    k + 1
                )
            )
        );

        visited.assign(
            n,
            vector<vector<bool>>(
                n + 1,
                vector<bool>(
                    k + 1
                )
            )
        );

        return solve(
            nums,
            k,
            0,
            -1,
            0
        );
    }
};
