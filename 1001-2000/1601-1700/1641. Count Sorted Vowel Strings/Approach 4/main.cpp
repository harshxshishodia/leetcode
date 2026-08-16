class Solution {
public:
    int countVowelStrings(int n) {
        array<int, 5> dp = {
            1,
            1,
            1,
            1,
            1
        };

        for (int length = 2;
             length <= n;
             length++) {
            for (int vowel = 1;
                 vowel < 5;
                 vowel++) {
                dp[vowel] +=
                    dp[vowel - 1];
            }
        }

        return accumulate(
            dp.begin(),
            dp.end(),
            0
        );
    }
};
