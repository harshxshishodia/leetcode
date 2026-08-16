class Solution {
    map<array<int, 4>, int> memo;

    int solve(
        int x,
        int y,
        int z,
        int last
    ) {
        array<int, 4> key = {
            x,
            y,
            z,
            last
        };

        auto found =
            memo.find(key);

        if (found != memo.end()) {
            return found->second;
        }

        int answer = 0;

        if (x > 0 &&
            last != 1) {
            answer = max(
                answer,
                2 +
                solve(
                    x - 1,
                    y,
                    z,
                    1
                )
            );
        }

        if (y > 0 &&
            (
                last == 0 ||
                last == 1
            )) {
            answer = max(
                answer,
                2 +
                solve(
                    x,
                    y - 1,
                    z,
                    2
                )
            );
        }

        if (z > 0 &&
            last != 1) {
            answer = max(
                answer,
                2 +
                solve(
                    x,
                    y,
                    z - 1,
                    3
                )
            );
        }

        memo[key] =
            answer;

        return answer;
    }

public:
    int longestString(
        int x,
        int y,
        int z
    ) {
        memo.clear();

        return solve(
            x,
            y,
            z,
            0
        );
    }
};
