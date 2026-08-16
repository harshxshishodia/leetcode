class Solution {
    int rangeSum(
        const vector<int>& prefix,
        int left,
        int right
    ) {
        if (left > right) {
            return 0;
        }

        return
            prefix[right + 1] -
            prefix[left];
    }

    int solve(
        const vector<int>& stones,
        const vector<int>& prefix,
        int left,
        int right
    ) {
        if (left == right) {
            return 0;
        }

        int removeLeft =
            rangeSum(
                prefix,
                left + 1,
                right
            ) -
            solve(
                stones,
                prefix,
                left + 1,
                right
            );

        int removeRight =
            rangeSum(
                prefix,
                left,
                right - 1
            ) -
            solve(
                stones,
                prefix,
                left,
                right - 1
            );

        return max(
            removeLeft,
            removeRight
        );
    }

public:
    int stoneGameVII(vector<int>& stones) {
        int n =
            static_cast<int>(stones.size());

        vector<int> prefix(
            n + 1
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                stones[i];
        }

        return solve(
            stones,
            prefix,
            0,
            n - 1
        );
    }
};
