class Solution {
    int solve(const string& s, int index) {
        if (index == static_cast<int>(s.size())) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        int answer = solve(s, index + 1);

        if (index + 1 < static_cast<int>(s.size())) {
            int value = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (value >= 10 && value <= 26) {
                answer += solve(s, index + 2);
            }
        }

        return answer;
    }

public:
    int numDecodings(string s) {
        return solve(s, 0);
    }
};
