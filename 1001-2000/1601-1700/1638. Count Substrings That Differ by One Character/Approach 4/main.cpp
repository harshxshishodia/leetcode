class Solution {
    int countDiagonal(
        const string& s,
        const string& t,
        int first,
        int second
    ) {
        int answer = 0;
        int lastMismatch = -1;
        int previousMismatch = -1;
        int position = 0;

        while (first < static_cast<int>(s.size()) &&
               second < static_cast<int>(t.size())) {
            if (s[first] != t[second]) {
                previousMismatch =
                    lastMismatch;

                lastMismatch =
                    position;
            }

            if (lastMismatch != -1) {
                answer +=
                    lastMismatch -
                    previousMismatch;
            }

            first++;
            second++;
            position++;
        }

        return answer;
    }

public:
    int countSubstrings(
        string s,
        string t
    ) {
        int answer = 0;

        for (int first = 0;
             first < static_cast<int>(s.size());
             first++) {
            answer +=
                countDiagonal(
                    s,
                    t,
                    first,
                    0
                );
        }

        for (int second = 1;
             second < static_cast<int>(t.size());
             second++) {
            answer +=
                countDiagonal(
                    s,
                    t,
                    0,
                    second
                );
        }

        return answer;
    }
};
