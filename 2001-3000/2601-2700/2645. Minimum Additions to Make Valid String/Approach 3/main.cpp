class Solution {
public:
    int addMinimum(string word) {
        int groups = 1;

        for (int index = 1;
             index < static_cast<int>(word.size());
             index++) {
            if (word[index] <=
                word[index - 1]) {
                groups++;
            }
        }

        return
            groups *
            3 -
            static_cast<int>(word.size());
    }
};
