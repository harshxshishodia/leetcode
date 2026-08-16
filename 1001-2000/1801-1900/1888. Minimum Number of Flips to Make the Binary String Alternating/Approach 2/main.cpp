class Solution {
public:
    int minFlips(string s) {
        int n =
            static_cast<int>(s.size());

        string doubled =
            s + s;

        vector<int> mismatchFirst(
            2 * n + 1
        );

        vector<int> mismatchSecond(
            2 * n + 1
        );

        for (int i = 0; i < 2 * n; i++) {
            char first =
                i % 2 == 0
                    ? '0'
                    : '1';

            char second =
                i % 2 == 0
                    ? '1'
                    : '0';

            mismatchFirst[i + 1] =
                mismatchFirst[i] +
                (doubled[i] != first);

            mismatchSecond[i + 1] =
                mismatchSecond[i] +
                (doubled[i] != second);
        }

        int answer = n;

        for (int start = 0; start < n; start++) {
            int end =
                start + n;

            int first =
                mismatchFirst[end] -
                mismatchFirst[start];

            int second =
                mismatchSecond[end] -
                mismatchSecond[start];

            answer = min({
                answer,
                first,
                second
            });
        }

        return answer;
    }
};
