class Solution {
public:
    int minFlips(string s) {
        int n =
            static_cast<int>(s.size());

        string doubled =
            s + s;

        int mismatchFirst = 0;
        int mismatchSecond = 0;
        int answer = n;

        for (int right = 0;
             right < 2 * n;
             right++) {
            char first =
                right % 2 == 0
                    ? '0'
                    : '1';

            char second =
                right % 2 == 0
                    ? '1'
                    : '0';

            mismatchFirst +=
                doubled[right] != first;

            mismatchSecond +=
                doubled[right] != second;

            if (right >= n) {
                int left =
                    right - n;

                char oldFirst =
                    left % 2 == 0
                        ? '0'
                        : '1';

                char oldSecond =
                    left % 2 == 0
                        ? '1'
                        : '0';

                mismatchFirst -=
                    doubled[left] != oldFirst;

                mismatchSecond -=
                    doubled[left] != oldSecond;
            }

            if (right >= n - 1) {
                answer = min({
                    answer,
                    mismatchFirst,
                    mismatchSecond
                });
            }
        }

        return answer;
    }
};
