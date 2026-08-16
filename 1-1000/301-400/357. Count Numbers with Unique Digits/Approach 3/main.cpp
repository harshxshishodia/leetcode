class Solution {
    string bound;
    int memo[11][1 << 10][2];
    bool visited[11][1 << 10][2];

    int solve(
        int position,
        int mask,
        int started,
        bool tight
    ) {
        if (position == static_cast<int>(bound.size())) {
            return 1;
        }

        if (!tight && visited[position][mask][started]) {
            return memo[position][mask][started];
        }

        int limit = tight ? bound[position] - '0' : 9;
        int answer = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight = tight && digit == limit;

            if (!started && digit == 0) {
                answer += solve(
                    position + 1,
                    mask,
                    0,
                    nextTight
                );
                continue;
            }

            if ((mask & (1 << digit)) == 0) {
                answer += solve(
                    position + 1,
                    mask | (1 << digit),
                    1,
                    nextTight
                );
            }
        }

        if (!tight) {
            visited[position][mask][started] = true;
            memo[position][mask][started] = answer;
        }

        return answer;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        n = min(n, 10);
        bound = string(n, '9');
        memset(visited, 0, sizeof(visited));

        return solve(0, 0, 0, true);
    }
};
