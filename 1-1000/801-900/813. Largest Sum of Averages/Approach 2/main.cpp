class Solution {
    vector<double> prefix;
    vector<vector<double>> memo;
    vector<vector<bool>> visited;
    int n;

    double average(
        int left,
        int right
    ) {
        return
            (
                prefix[right] -
                prefix[left]
            ) /
            (right - left);
    }

    double solve(
        int start,
        int groups
    ) {
        if (groups == 1) {
            return average(
                start,
                n
            );
        }

        if (visited[start][groups]) {
            return memo[start][groups];
        }

        visited[start][groups] = true;
        double answer = 0.0;

        for (int end = start + 1;
             end <= n - groups + 1;
             end++) {
            answer = max(
                answer,
                average(
                    start,
                    end
                ) +
                solve(
                    end,
                    groups - 1
                )
            );
        }

        memo[start][groups] = answer;
        return memo[start][groups];
    }

public:
    double largestSumOfAverages(
        vector<int>& nums,
        int k
    ) {
        n = static_cast<int>(nums.size());

        prefix.assign(
            n + 1,
            0.0
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                nums[i];
        }

        memo.assign(
            n,
            vector<double>(
                k + 1
            )
        );

        visited.assign(
            n,
            vector<bool>(
                k + 1
            )
        );

        return solve(
            0,
            k
        );
    }
};
