class Solution {
    bool collinear(
        const vector<int>& first,
        const vector<int>& second,
        const vector<int>& third
    ) {
        return
            1LL *
            (second[0] - first[0]) *
            (third[1] - first[1]) ==
            1LL *
            (second[1] - first[1]) *
            (third[0] - first[0]);
    }

    int solve(
        const vector<vector<int>>& points,
        int covered
    ) {
        int n =
            static_cast<int>(points.size());

        int full =
            (1 << n) -
            1;

        if (covered == full) {
            return 0;
        }

        int first = 0;

        while ((covered & (1 << first)) != 0) {
            first++;
        }

        int uncovered =
            n -
            __builtin_popcount(
                static_cast<unsigned int>(covered)
            );

        if (uncovered <= 2) {
            return 1;
        }

        int answer =
            uncovered;

        for (int second = first + 1;
             second < n;
             second++) {
            if ((covered & (1 << second)) != 0) {
                continue;
            }

            int next =
                covered |
                (1 << first) |
                (1 << second);

            for (int third = 0;
                 third < n;
                 third++) {
                if (collinear(
                        points[first],
                        points[second],
                        points[third])) {
                    next |=
                        1 << third;
                }
            }

            answer = min(
                answer,
                1 +
                solve(
                    points,
                    next
                )
            );
        }

        return answer;
    }

public:
    int minimumLines(vector<vector<int>>& points) {
        if (points.size() <= 2) {
            return 1;
        }

        return solve(
            points,
            0
        );
    }
};
