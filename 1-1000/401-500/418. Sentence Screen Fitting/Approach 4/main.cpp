class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string joined;

        for (const string& word : sentence) {
            joined += word;
            joined += ' ';
        }

        int length = static_cast<int>(joined.size());
        vector<int> adjustment(length);

        for (int i = 1; i < length; i++) {
            adjustment[i] = adjustment[i - 1];

            if (joined[i] == ' ') {
                adjustment[i] = 1;
            } else {
                adjustment[i]--;
            }
        }

        long long position = 0;

        for (int row = 0; row < rows; row++) {
            position += cols;
            position += adjustment[position % length];
        }

        return static_cast<int>(position / length);
    }
};
