class Solution {
    int getMinCandies(const vector<int>& ratings, int index, vector<int>& memo) {
        if (memo[index] != -1) {
            return memo[index];
        }

        int required = 1;
        int n = static_cast<int>(ratings.size());

        if (index > 0 && ratings[index] > ratings[index - 1]) {
            required = max(required, 1 + getMinCandies(ratings, index - 1, memo));
        }

        if (index < n - 1 && ratings[index] > ratings[index + 1]) {
            required = max(required, 1 + getMinCandies(ratings, index + 1, memo));
        }

        return memo[index] = required;
    }

public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        vector<int> memo(n, -1);
        int totalCandies = 0;

        for (int i = 0; i < n; i++) {
            totalCandies += getMinCandies(ratings, i, memo);
        }

        return totalCandies;
    }
};
