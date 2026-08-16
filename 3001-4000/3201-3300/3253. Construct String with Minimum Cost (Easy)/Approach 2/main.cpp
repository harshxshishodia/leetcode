class Solution {
    static constexpr int INF = 1000000000;

    int solve(
        const string& target,
        const vector<string>& words,
        const vector<int>& costs,
        int index,
        vector<int>& dp
    ) {
        if (index == static_cast<int>(target.size())) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int answer = INF;

        for (int i = 0; i < static_cast<int>(words.size()); i++) {
            int length = static_cast<int>(words[i].size());

            if (index + length <= static_cast<int>(target.size()) &&
                target.compare(index, length, words[i]) == 0) {
                int next = solve(target, words, costs, index + length, dp);

                if (next != INF) {
                    answer = min(answer, costs[i] + next);
                }
            }
        }

        dp[index] = answer;
        return dp[index];
    }

public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        vector<int> dp(target.size(), -1);
        int answer = solve(target, words, costs, 0, dp);
        return answer == INF ? -1 : answer;
    }
};
