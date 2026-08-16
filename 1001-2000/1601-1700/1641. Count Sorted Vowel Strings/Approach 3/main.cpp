class Solution {
public:
    int countVowelStrings(int n) {
        vector<array<int, 5>> dp(
            n + 1
        );

        for (int vowel = 0; vowel < 5; vowel++) {
            dp[1][vowel] = 1;
        }

        for (int length = 2;
             length <= n;
             length++) {
            for (int vowel = 0;
                 vowel < 5;
                 vowel++) {
                for (int previous = 0;
                     previous <= vowel;
                     previous++) {
                    dp[length][vowel] +=
                        dp[length - 1][previous];
                }
            }
        }

        int answer = 0;

        for (int vowel = 0; vowel < 5; vowel++) {
            answer +=
                dp[n][vowel];
        }

        return answer;
    }
};
