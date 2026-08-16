class Solution {
public:
    int countSubstrings(
        string s,
        string t
    ) {
        int answer = 0;

        for (int first = 0;
             first < static_cast<int>(s.size());
             first++) {
            for (int second = 0;
                 second < static_cast<int>(t.size());
                 second++) {
                int difference = 0;

                for (int length = 1;
                     first + length <= static_cast<int>(s.size()) &&
                     second + length <= static_cast<int>(t.size());
                     length++) {
                    if (s[first + length - 1] !=
                        t[second + length - 1]) {
                        difference++;
                    }

                    if (difference == 1) {
                        answer++;
                    } else if (difference > 1) {
                        break;
                    }
                }
            }
        }

        return answer;
    }
};
