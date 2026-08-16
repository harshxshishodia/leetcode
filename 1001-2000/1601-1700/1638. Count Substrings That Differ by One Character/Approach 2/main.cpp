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
                if (s[first] == t[second]) {
                    continue;
                }

                int left = 0;

                while (first - left - 1 >= 0 &&
                       second - left - 1 >= 0 &&
                       s[first - left - 1] ==
                       t[second - left - 1]) {
                    left++;
                }

                int right = 0;

                while (first + right + 1 <
                           static_cast<int>(s.size()) &&
                       second + right + 1 <
                           static_cast<int>(t.size()) &&
                       s[first + right + 1] ==
                       t[second + right + 1]) {
                    right++;
                }

                answer +=
                    (left + 1) *
                    (right + 1);
            }
        }

        return answer;
    }
};
