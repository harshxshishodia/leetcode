class Solution {
    int solve(
        const string& first,
        const string& second,
        int i,
        int j
    ) {
        if (i == static_cast<int>(first.size())) {
            return static_cast<int>(second.size()) - j;
        }

        if (j == static_cast<int>(second.size())) {
            return static_cast<int>(first.size()) - i;
        }

        if (first[i] == second[j]) {
            return solve(
                first,
                second,
                i + 1,
                j + 1
            );
        }

        return 1 + min(
            solve(first, second, i + 1, j),
            solve(first, second, i, j + 1)
        );
    }

public:
    int minDistance(string word1, string word2) {
        return solve(word1, word2, 0, 0);
    }
};
