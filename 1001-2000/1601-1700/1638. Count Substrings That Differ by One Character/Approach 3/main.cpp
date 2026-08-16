class Solution {
public:
    int countSubstrings(
        string s,
        string t
    ) {
        int firstLength =
            static_cast<int>(s.size());

        int secondLength =
            static_cast<int>(t.size());

        vector<vector<int>> left(
            firstLength + 1,
            vector<int>(
                secondLength + 1
            )
        );

        vector<vector<int>> right(
            firstLength + 1,
            vector<int>(
                secondLength + 1
            )
        );

        for (int first = 0;
             first < firstLength;
             first++) {
            for (int second = 0;
                 second < secondLength;
                 second++) {
                if (s[first] == t[second]) {
                    left[first + 1][second + 1] =
                        left[first][second] +
                        1;
                }
            }
        }

        for (int first = firstLength - 1;
             first >= 0;
             first--) {
            for (int second = secondLength - 1;
                 second >= 0;
                 second--) {
                if (s[first] == t[second]) {
                    right[first][second] =
                        right[first + 1][second + 1] +
                        1;
                }
            }
        }

        int answer = 0;

        for (int first = 0;
             first < firstLength;
             first++) {
            for (int second = 0;
                 second < secondLength;
                 second++) {
                if (s[first] != t[second]) {
                    answer +=
                        (
                            left[first][second] +
                            1
                        ) *
                        (
                            right[first + 1][second + 1] +
                            1
                        );
                }
            }
        }

        return answer;
    }
};
