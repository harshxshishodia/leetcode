class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string joined;

        for (const string& word : sentence) {
            joined += word;
            joined += ' ';
        }

        int length = static_cast<int>(joined.size());
        long long position = 0;

        for (int row = 0; row < rows; row++) {
            position += cols;

            if (joined[position % length] == ' ') {
                position++;
            } else {
                while (position > 0 &&
                       joined[(position - 1) % length] != ' ') {
                    position--;
                }
            }
        }

        return static_cast<int>(position / length);
    }
};
