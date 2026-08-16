class Solution {
    bool solve(
        const string& s,
        int start,
        const unordered_set<string>& words,
        vector<int>& memo
    ) {
        if (start == static_cast<int>(s.size())) {
            return true;
        }

        if (memo[start] != -1) {
            return memo[start];
        }

        for (int end = start; end < static_cast<int>(s.size()); end++) {
            if (words.count(s.substr(start, end - start + 1)) &&
                solve(s, end + 1, words, memo)) {
                return memo[start] = 1;
            }
        }

        return memo[start] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);

        return solve(s, 0, words, memo);
    }
};
