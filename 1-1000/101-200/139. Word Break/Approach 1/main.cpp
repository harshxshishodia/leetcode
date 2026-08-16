class Solution {
    bool contains(const vector<string>& wordDict, const string& word) {
        for (const string& candidate : wordDict) {
            if (candidate == word) {
                return true;
            }
        }

        return false;
    }

    bool solve(const string& s, const vector<string>& wordDict, int start) {
        if (start == static_cast<int>(s.size())) {
            return true;
        }

        for (int end = start; end < static_cast<int>(s.size()); end++) {
            string word = s.substr(start, end - start + 1);

            if (contains(wordDict, word) &&
                solve(s, wordDict, end + 1)) {
                return true;
            }
        }

        return false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict, 0);
    }
};
