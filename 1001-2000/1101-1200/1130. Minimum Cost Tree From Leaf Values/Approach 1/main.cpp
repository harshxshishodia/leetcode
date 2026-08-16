class Solution {
    int maximum(
        const vector<int>& arr,
        int left,
        int right
    ) {
        int answer = 0;

        for (int i = left; i <= right; i++) {
            answer = max(
                answer,
                arr[i]
            );
        }

        return answer;
    }

    int solve(
        const vector<int>& arr,
        int left,
        int right
    ) {
        if (left == right) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int split = left;
             split < right;
             split++) {
            answer = min(
                answer,
                solve(
                    arr,
                    left,
                    split
                ) +
                solve(
                    arr,
                    split + 1,
                    right
                ) +
                maximum(
                    arr,
                    left,
                    split
                ) *
                maximum(
                    arr,
                    split + 1,
                    right
                )
            );
        }

        return answer;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        return solve(
            arr,
            0,
            static_cast<int>(arr.size()) - 1
        );
    }
};
