class Solution {
    int solve(
        int remaining,
        int minimumVowel
    ) {
        if (remaining == 0) {
            return 1;
        }

        int answer = 0;

        for (int vowel = minimumVowel;
             vowel < 5;
             vowel++) {
            answer +=
                solve(
                    remaining - 1,
                    vowel
                );
        }

        return answer;
    }

public:
    int countVowelStrings(int n) {
        return solve(
            n,
            0
        );
    }
};
