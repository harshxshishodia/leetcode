class Solution {
    vector<vector<int>> memo;
    vector<vector<bool>> visited;
    vector<int> prefix;

    int sum(
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
        int left,
        int right
    ) {
        if (left == right) {
            return 0;
        }

        if (visited[left][right]) {
            return memo[left][right];
        }

        visited[left][right] = true;

        int removeLeft =
            sum(
                left + 1,
                right
            ) -
            solve(
                left + 1,
                right
            );

        int removeRight =
            sum(
                left,
                right - 1
            ) -
            solve(
                left,
                right - 1
            );

        memo[left][right] = max(
            removeLeft,
            removeRight
        );

        return memo[left][right];
    }

public:
    int stoneGameVII(vector<int>& stones) {
        int n =
            static_cast<int>(stones.size());

        prefix.assign(
            n + 1,
            0
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                stones[i];
        }

        memo.assign(
            n,
            vector<int>(n)
        );

        visited.assign(
            n,
            vector<bool>(n)
        );

        return solve(
            0,
            n - 1
        );
    }
};
