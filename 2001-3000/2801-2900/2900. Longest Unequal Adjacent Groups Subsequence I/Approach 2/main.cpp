class Solution {
    int solve(
        const vector<int>& groups,
        int index,
        int previousIndex,
        vector<vector<int>>& dp
    ) {
        if (index == static_cast<int>(groups.size())) {
            return 0;
        }

        int previousState = previousIndex + 1;

        if (dp[index][previousState] != -1) {
            return dp[index][previousState];
        }

        int skip = solve(groups, index + 1, previousIndex, dp);
        int take = 0;

        if (previousIndex == -1 || groups[index] != groups[previousIndex]) {
            take = 1 + solve(groups, index + 1, index, dp);
        }

        dp[index][previousState] = max(skip, take);
        return dp[index][previousState];
    }

public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = static_cast<int>(words.size());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<string> answer;
        int index = 0;
        int previousIndex = -1;

        while (index < n) {
            int skip = solve(groups, index + 1, previousIndex, dp);
            int take = -1;

            if (previousIndex == -1 || groups[index] != groups[previousIndex]) {
                take = 1 + solve(groups, index + 1, index, dp);
            }

            if (take >= skip) {
                answer.push_back(words[index]);
                previousIndex = index;
            }

            index++;
        }

        return answer;
    }
};
