class Solution {
    int solve(
        const vector<int>& arr,
        int k,
        int index,
        vector<int>& memo
    ) {
        if (index == static_cast<int>(arr.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int maximum = 0;
        int answer = 0;

        for (int end = index;
             end < static_cast<int>(arr.size()) &&
             end < index + k;
             end++) {
            maximum = max(
                maximum,
                arr[end]
            );

            int length =
                end - index + 1;

            answer = max(
                answer,
                maximum * length +
                solve(
                    arr,
                    k,
                    end + 1,
                    memo
                )
            );
        }

        memo[index] = answer;
        return memo[index];
    }

public:
    int maxSumAfterPartitioning(
        vector<int>& arr,
        int k
    ) {
        vector<int> memo(
            arr.size(),
            -1
        );

        return solve(
            arr,
            k,
            0,
            memo
        );
    }
};
