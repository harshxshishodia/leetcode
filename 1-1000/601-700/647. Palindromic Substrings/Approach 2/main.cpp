class Solution {
    int palindrome(
        const string& s,
        int left,
        int right,
        vector<vector<int>>& memo
    ) {
        if (left >= right) {
            return 1;
        }

        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        if (s[left] != s[right]) {
            memo[left][right] = 0;
        } else {
            memo[left][right] = palindrome(
                s,
                left + 1,
                right - 1,
                memo
            );
        }

        return memo[left][right];
    }

public:
    int countSubstrings(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> memo(
            n,
            vector<int>(n, -1)
        );

        int answer = 0;

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                answer += palindrome(
                    s,
                    left,
                    right,
                    memo
                );
            }
        }

        return answer;
    }
};
