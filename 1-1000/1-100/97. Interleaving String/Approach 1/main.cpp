class Solution {
    bool solve(
        const string& first,
        const string& second,
        const string& target,
        int i,
        int j
    ) {
        int k = i + j;

        if (k == static_cast<int>(target.size())) {
            return i == static_cast<int>(first.size()) &&
                   j == static_cast<int>(second.size());
        }

        bool possible = false;

        if (i < static_cast<int>(first.size()) &&
            first[i] == target[k]) {
            possible = solve(first, second, target, i + 1, j);
        }

        if (!possible &&
            j < static_cast<int>(second.size()) &&
            second[j] == target[k]) {
            possible = solve(first, second, target, i, j + 1);
        }

        return possible;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        return solve(s1, s2, s3, 0, 0);
    }
};
