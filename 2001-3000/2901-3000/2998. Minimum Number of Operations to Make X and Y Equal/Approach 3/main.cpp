class Solution {
    unordered_map<int, int> memo;
    int target;

    int solve(int value) {
        if (value <= target) {
            return
                target -
                value;
        }

        auto found =
            memo.find(value);

        if (found != memo.end()) {
            return found->second;
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
                    divisor
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
                        divisor
                    )
                );
            }
        }

        memo[value] =
            answer;

        return answer;
    }

public:
    int minimumOperationsToMakeEqual(
        int x,
        int y
    ) {
        target =
            y;

        memo.clear();

        return solve(x);
    }
};
