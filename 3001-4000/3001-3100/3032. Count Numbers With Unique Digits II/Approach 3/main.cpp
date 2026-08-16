class Solution {
    string digits;
    long long memo[11][1 << 10][2];
    bool visited[11][1 << 10][2];

    long long solve(int position, int mask, int started, bool tight) {
        if (position == static_cast<int>(digits.size())) {
            return started;
        }

        if (!tight && visited[position][mask][started]) {
            return memo[position][mask][started];
        }

        int limit = tight ? digits[position] - '0' : 9;
        long long answer = 0;

        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight = tight && digit == limit;

            if (!started && digit == 0) {
                answer += solve(position + 1, mask, 0, nextTight);
                continue;
            }

            if ((mask & (1 << digit)) == 0) {
                answer += solve(position + 1, mask | (1 << digit), 1, nextTight);
            }
        }

        if (!tight) {
            visited[position][mask][started] = true;
            memo[position][mask][started] = answer;
        }

        return answer;
    }

    long long countUpTo(int limit) {
        if (limit <= 0) {
            return 0;
        }

        digits = to_string(limit);
        memset(visited, 0, sizeof(visited));
        return solve(0, 0, 0, true);
    }

public:
    int numberCount(int a, int b) {
        return static_cast<int>(countUpTo(b) - countUpTo(a - 1));
    }
};
