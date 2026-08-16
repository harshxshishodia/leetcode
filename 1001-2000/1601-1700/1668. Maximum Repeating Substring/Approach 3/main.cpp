class Solution {
    bool matches(const string& sequence, const string& word, int start) {
        if (start + static_cast<int>(word.size()) > static_cast<int>(sequence.size())) {
            return false;
        }

        for (int i = 0; i < static_cast<int>(word.size()); i++) {
            if (sequence[start + i] != word[i]) {
                return false;
            }
        }

        return true;
    }

public:
    int maxRepeating(string sequence, string word) {
        int answer = 0;
        int n = static_cast<int>(sequence.size());
        int m = static_cast<int>(word.size());

        for (int start = 0; start < n; start++) {
            int count = 0;
            int position = start;

            while (position + m <= n && matches(sequence, word, position)) {
                count++;
                position += m;
            }

            answer = max(answer, count);
        }

        return answer;
    }
};
