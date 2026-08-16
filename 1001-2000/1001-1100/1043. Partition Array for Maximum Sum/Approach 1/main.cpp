class Solution {
    int solve(
        const vector<int>& arr,
        int k,
        int index
    ) {
        if (index == static_cast<int>(arr.size())) {
            return 0;
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
                    end + 1
                )
            );
        }

        return answer;
    }

public:
    int maxSumAfterPartitioning(
        vector<int>& arr,
        int k
    ) {
        return solve(
            arr,
            k,
            0
        );
    }
};
