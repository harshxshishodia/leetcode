class Solution {
    void backtrack(
        const string& s,
        int start,
        const vector<vector<bool>>& palindrome,
        vector<string>& current,
        vector<vector<string>>& answer
    ) {
        if (start == static_cast<int>(s.size())) {
            answer.push_back(current);
            return;
        }

        for (int end = start; end < static_cast<int>(s.size()); end++) {
            if (!palindrome[start][end]) {
                continue;
            }

            current.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, palindrome, current, answer);
            current.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<bool>> palindrome(n, vector<bool>(n));

        for (int right = 0; right < n; right++) {
            for (int left = right; left >= 0; left--) {
                palindrome[left][right] =
                    s[left] == s[right] &&
                    (right - left <= 2 || palindrome[left + 1][right - 1]);
            }
        }

        vector<vector<string>> answer;
        vector<string> current;
        backtrack(s, 0, palindrome, current, answer);
        return answer;
    }
};
