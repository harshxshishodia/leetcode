class Solution {
    bool vowel(char character) {
        return
            character == 'a' ||
            character == 'e' ||
            character == 'i' ||
            character == 'o' ||
            character == 'u';
    }

public:
    long long countVowels(string word) {
        long long answer = 0;
        int n =
            static_cast<int>(word.size());

        for (int index = 0; index < n; index++) {
            if (vowel(word[index])) {
                answer +=
                    1LL *
                    (index + 1) *
                    (n - index);
            }
        }

        return answer;
    }
};
