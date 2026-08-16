class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int answer = 0;

        for (int index = 1;
             index < static_cast<int>(word.size());
             index++) {
            if (abs(
                    word[index] -
                    word[index - 1]
                ) <= 1) {
                answer++;
                index++;
            }
        }

        return answer;
    }
};
