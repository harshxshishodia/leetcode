class Solution {
    string digits;
    int memo[6][2][2];
    bool visited[6][2][2];

    int solve(
        int position,
        int started,
        int changed,
        bool tight
    ) {
        if (position == static_cast<int>(digits.size())) {
            return started && changed;
        }

        if (!tight &&
            visited[position][started][changed]) {
            return memo[position][started][changed];
        }

        int limit =
            tight
                ? digits[position] - '0'
                : 9;

        int answer = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight =
                tight && digit == limit;

            if (!started && digit == 0) {
                answer += solve(
                    position + 1,
                    0,
                    0,
                    nextTight
                );

                continue;
            }

            if (digit == 3 ||
                digit == 4 ||
                digit == 7) {
                continue;
            }

            int nextChanged =
                changed ||
                digit == 2 ||
                digit == 5 ||
                digit == 6 ||
                digit == 9;

            answer += solve(
                position + 1,
                1,
                nextChanged,
                nextTight
            );
        }

        if (!tight) {
            visited[position][started][changed] = true;
            memo[position][started][changed] = answer;
        }

        return answer;
    }

public:
    int rotatedDigits(int n) {
        digits = to_string(n);
        memset(
            visited,
            0,
            sizeof(visited)
        );

        return solve(
            0,
            0,
            0,
            true
        );
    }
};
