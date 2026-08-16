class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = static_cast<int>(sentence.size());
        vector<int> nextWord(n);
        vector<int> completed(n);

        for (int start = 0; start < n; start++) {
            int col = 0;
            int word = start;
            int count = 0;

            while (col + static_cast<int>(sentence[word].size()) <= cols) {
                col += static_cast<int>(sentence[word].size()) + 1;
                word++;

                if (word == n) {
                    word = 0;
                    count++;
                }
            }

            nextWord[start] = word;
            completed[start] = count;
        }

        int word = 0;
        int answer = 0;

        for (int row = 0; row < rows; row++) {
            answer += completed[word];
            word = nextWord[word];
        }

        return answer;
    }
};
