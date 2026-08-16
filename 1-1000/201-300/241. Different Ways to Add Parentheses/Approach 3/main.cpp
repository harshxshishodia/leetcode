class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> numbers;
        vector<char> operations;
        int value = 0;
        bool building = false;

        for (char character : expression) {
            if (isdigit(character)) {
                value = value * 10 + (character - '0');
                building = true;
            } else {
                numbers.push_back(value);
                operations.push_back(character);
                value = 0;
                building = false;
            }
        }

        if (building) {
            numbers.push_back(value);
        }

        int n = static_cast<int>(numbers.size());
        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n)
        );

        for (int i = 0; i < n; i++) {
            dp[i][i] = {numbers[i]};
        }

        for (int length = 2; length <= n; length++) {
            for (int left = 0; left + length <= n; left++) {
                int right = left + length - 1;

                for (int split = left; split < right; split++) {
                    char operation = operations[split];

                    for (int first : dp[left][split]) {
                        for (int second : dp[split + 1][right]) {
                            if (operation == '+') {
                                dp[left][right].push_back(first + second);
                            } else if (operation == '-') {
                                dp[left][right].push_back(first - second);
                            } else {
                                dp[left][right].push_back(first * second);
                            }
                        }
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
