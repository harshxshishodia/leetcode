class Solution {
    vector<double> prefix;

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
        int n,
        int start,
        int groups
    ) {
        if (groups == 1) {
            return average(
                start,
                n
            );
        }

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
                    n,
                    end,
                    groups - 1
                )
            );
        }

        return answer;
    }

public:
    double largestSumOfAverages(
        vector<int>& nums,
        int k
    ) {
        int n = static_cast<int>(nums.size());

        prefix.assign(
            n + 1,
            0.0
        );

        for (int i = 0; i < n; i++) {
            prefix[i + 1] =
                prefix[i] +
                nums[i];
        }

        return solve(
            n,
            0,
            k
        );
    }
};
