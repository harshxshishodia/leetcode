class Solution {
    int solve(
        int value,
        int target
    ) {
        if (value <= target) {
            return
                target -
                value;
        }

        int answer =
            value -
            target;

        for (int divisor :
             {5, 11}) {
            int remainder =
                value %
                divisor;

            answer = min(
                answer,
                remainder +
                1 +
                solve(
                    value /
                    divisor,
                    target
                )
            );

            int increase =
                (
                    divisor -
                    remainder
                ) %
                divisor;

            if (increase > 0) {
                answer = min(
                    answer,
                    increase +
                    1 +
                    solve(
                        (
                            value +
                            increase
                        ) /
                        divisor,
                        target
                    )
                );
            }
        }

        return answer;
    }

public:
    int minimumOperationsToMakeEqual(
        int x,
        int y
    ) {
        return solve(
            x,
            y
        );
    }
};
