class Solution {
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void backtrack(
        const string& s,
        int start,
        vector<string>& current,
        vector<vector<string>>& answer
    ) {
        if (start == static_cast<int>(s.size())) {
            answer.push_back(current);
            return;
        }

        for (int end = start; end < static_cast<int>(s.size()); end++) {
            if (!isPalindrome(s, start, end)) {
                continue;
            }

            current.push_back(s.substr(start, end - start + 1));
            backtrack(s, end + 1, current, answer);
            current.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        vector<string> current;
        backtrack(s, 0, current, answer);
        return answer;
    }
};
