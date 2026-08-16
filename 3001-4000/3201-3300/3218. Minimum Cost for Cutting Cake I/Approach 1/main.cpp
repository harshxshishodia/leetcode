class Solution {
    int solve(
        int top,
        int bottom,
        int left,
        int right,
        const vector<int>& horizontalCut,
        const vector<int>& verticalCut
    ) {
        if (top == bottom &&
            left == right) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max();

        for (int cut = top;
             cut < bottom;
             cut++) {
            answer = min(
                answer,
                horizontalCut[cut] +
                solve(
                    top,
                    cut,
                    left,
                    right,
                    horizontalCut,
                    verticalCut
                ) +
                solve(
                    cut + 1,
                    bottom,
                    left,
                    right,
                    horizontalCut,
                    verticalCut
                )
            );
        }

        for (int cut = left;
             cut < right;
             cut++) {
            answer = min(
                answer,
                verticalCut[cut] +
                solve(
                    top,
                    bottom,
                    left,
                    cut,
                    horizontalCut,
                    verticalCut
                ) +
                solve(
                    top,
                    bottom,
                    cut + 1,
                    right,
                    horizontalCut,
                    verticalCut
                )
            );
        }

        return answer;
    }

public:
    int minimumCost(
        int m,
        int n,
        vector<int>& horizontalCut,
        vector<int>& verticalCut
    ) {
        return solve(
            0,
            m - 1,
            0,
            n - 1,
            horizontalCut,
            verticalCut
        );
    }
};
