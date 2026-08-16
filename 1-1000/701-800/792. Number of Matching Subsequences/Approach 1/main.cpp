class Solution {
    bool subsequence(
        const string& s,
        const string& word
    ) {
        int index = 0;

        for (char character : s) {
            if (index < static_cast<int>(word.size()) &&
                word[index] == character) {
                index++;
            }
        }

        return index ==
               static_cast<int>(word.size());
    }

public:
    int numMatchingSubseq(
        string s,
        vector<string>& words
    ) {
        int answer = 0;

        for (const string& word : words) {
            if (subsequence(
                    s,
                    word)) {
                answer++;
            }
        }

        return answer;
    }
};
