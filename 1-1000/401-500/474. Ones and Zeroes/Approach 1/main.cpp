class Solution {
    pair<int, int> count(const string& s) {
        int zeroes = 0;
        int ones = 0;

        for (char character : s) {
            if (character == '0') {
                zeroes++;
            } else {
                ones++;
            }
        }

        return {zeroes, ones};
    }

    int solve(
        const vector<string>& strs,
        int index,
        int zeroes,
        int ones
    ) {
        if (index == static_cast<int>(strs.size())) {
            return 0;
        }

        int skip = solve(
            strs,
            index + 1,
            zeroes,
            ones
        );

        int take = 0;
        auto [neededZeroes, neededOnes] = count(strs[index]);

        if (neededZeroes <= zeroes &&
            neededOnes <= ones) {
            take = 1 + solve(
                strs,
                index + 1,
                zeroes - neededZeroes,
                ones - neededOnes
            );
        }

        return max(skip, take);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        return solve(strs, 0, m, n);
    }
};
