class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int maximum = static_cast<int>(sequence.size() / word.size());

        for (int count = maximum; count >= 1; count--) {
            string repeated;

            for (int i = 0; i < count; i++) {
                repeated += word;
            }

            if (sequence.find(repeated) != string::npos) {
                return count;
            }
        }

        return 0;
    }
};
