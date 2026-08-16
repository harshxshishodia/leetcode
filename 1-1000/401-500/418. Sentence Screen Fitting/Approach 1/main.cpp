class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int word = 0;
        int completed = 0;

        for (int row = 0; row < rows; row++) {
            int col = 0;

            while (col < cols) {
                int length = static_cast<int>(sentence[word].size());

                if (col + length > cols) {
                    break;
                }

                col += length;

                if (col < cols) {
                    col++;
                }

                word++;

                if (word == static_cast<int>(sentence.size())) {
                    word = 0;
                    completed++;
                }
            }
        }

        return completed;
    }
};
