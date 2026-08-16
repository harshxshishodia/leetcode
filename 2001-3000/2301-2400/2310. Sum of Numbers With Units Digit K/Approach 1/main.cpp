class Solution {
    int solve(
        int remaining,
        int k
    ) {
        if (remaining == 0) {
            return 0;
        }

        int answer =
            numeric_limits<int>::max() / 4;

        int first =
            k == 0
                ? 10
                : k;

        for (int value = first;
             value <= remaining;
             value += 10) {
            answer = min(
                answer,
                1 +
                solve(
                    remaining - value,
                    k
                )
            );
        }

        return answer;
    }

public:
    int minimumNumbers(
        int num,
        int k
    ) {
        int answer =
            solve(
                num,
                k
            );

        return answer >=
               numeric_limits<int>::max() / 8
            ? -1
            : answer;
    }
};
