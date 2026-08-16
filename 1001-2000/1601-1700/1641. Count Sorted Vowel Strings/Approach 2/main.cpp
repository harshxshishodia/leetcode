class Solution {
    vector<array<int, 5>> memo;
    vector<array<bool, 5>> visited;

    int solve(
        int remaining,
        int minimumVowel
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (visited[remaining][minimumVowel]) {
            return memo[remaining][minimumVowel];
        }

        visited[remaining][minimumVowel] = true;

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

        memo[remaining][minimumVowel] =
            answer;

        return memo[remaining][minimumVowel];
    }

public:
    int countVowelStrings(int n) {
        memo.assign(
            n + 1,
            {}
        );

        visited.assign(
            n + 1,
            {}
        );

        return solve(
            n,
            0
        );
    }
};
