class Solution {
public:
    long long numberOfWays(string s) {
        int n =
            static_cast<int>(s.size());

        long long answer = 0;

        for (int first = 0; first < n; first++) {
            for (int second = first + 1;
                 second < n;
                 second++) {
                for (int third = second + 1;
                     third < n;
                     third++) {
                    if (s[first] != s[second] &&
                        s[second] != s[third]) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};
