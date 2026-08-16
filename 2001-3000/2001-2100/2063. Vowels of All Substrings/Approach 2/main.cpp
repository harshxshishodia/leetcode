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
        int n =
            static_cast<int>(word.size());

        long long answer = 0;

        for (int left = 0; left < n; left++) {
            long long count = 0;

            for (int right = left; right < n; right++) {
                count +=
                    vowel(word[right]);

                answer +=
                    count;
            }
        }

        return answer;
    }
};
