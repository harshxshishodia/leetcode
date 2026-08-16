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
            memo[left][right] = palindrome(s, left + 1, right - 1, memo);
        }

        return memo[left][right];
    }

    void backtrack(
        const string& s,
        int start,
        vector<vector<int>>& memo,
        vector<string>& current,
        vector<vector<string>>& answer
    ) {
        if (start == static_cast<int>(s.size())) {
            answer.push_back(current);
            return;
        }

        for (int end = start; end < static_cast<int>(s.size()); end++) {
            if (!palindrome(s, start, end, memo)) {
                continue;
            }

            current.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, memo, current, answer);
            current.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<int>> memo(n, vector<int>(n, -1));
        vector<vector<string>> answer;
        vector<string> current;

        backtrack(s, 0, memo, current, answer);
        return answer;
    }
};
