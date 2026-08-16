class Solution {
    int mismatch(
        const string& s
    ) {
        int first = 0;
        int second = 0;

        for (int i = 0;
             i < static_cast<int>(s.size());
             i++) {
            char expectedFirst =
                i % 2 == 0
                    ? '0'
                    : '1';

            char expectedSecond =
                i % 2 == 0
                    ? '1'
                    : '0';

            first +=
                s[i] != expectedFirst;

            second +=
                s[i] != expectedSecond;
        }

        return min(
            first,
            second
        );
    }

public:
    int minFlips(string s) {
        int n =
            static_cast<int>(s.size());

        int answer = n;

        for (int rotation = 0;
             rotation < n;
             rotation++) {
            string current =
                s.substr(rotation) +
                s.substr(0, rotation);

            answer = min(
                answer,
                mismatch(current)
            );
        }

        return answer;
    }
};
