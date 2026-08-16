class Solution {
    int solve(
        const vector<int>& arr,
        int difference,
        int index,
        int previous
    ) {
        if (index == static_cast<int>(arr.size())) {
            return 0;
        }

        int skip = solve(
            arr,
            difference,
            index + 1,
            previous
        );

        int take = 0;

        if (previous == -1 ||
            arr[index] - arr[previous] == difference) {
            take =
                1 +
                solve(
                    arr,
                    difference,
                    index + 1,
                    index
                );
        }

        return max(
            skip,
            take
        );
    }

public:
    int longestSubsequence(
        vector<int>& arr,
        int difference
    ) {
        return solve(
            arr,
            difference,
            0,
            -1
        );
    }
};
