class Solution {
    bool beautiful(
        const string& s,
        int left,
        int right
    ) {
        if (s[left] == '0') {
            return false;
        }

        long long value = 0;

        for (int index = left;
             index <= right;
             index++) {
            value =
                value *
                2 +
                (
                    s[index] -
                    '0'
                );
        }

        while (value > 1 &&
               value % 5 == 0) {
            value /=
                5;
        }

        return value == 1;
    }

    int solve(
        const string& s,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            return 0;
        }

        const int INF =
            1000000000;

        int answer = INF;

        for (int end = index;
             end < static_cast<int>(s.size());
             end++) {
            if (!beautiful(
                    s,
                    index,
                    end)) {
                continue;
            }

            int next =
                solve(
                    s,
                    end + 1
                );

            if (next != INF) {
                answer = min(
                    answer,
                    1 + next
                );
            }
        }

        return answer;
    }

public:
    int minimumBeautifulSubstrings(string s) {
        const int INF =
            1000000000;

        int answer =
            solve(
                s,
                0
            );

        return answer == INF
            ? -1
            : answer;
    }
};
