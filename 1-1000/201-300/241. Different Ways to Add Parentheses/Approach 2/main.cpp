class Solution {
    vector<int> solve(
        const string& expression,
        int left,
        int right,
        map<pair<int, int>, vector<int>>& memo
    ) {
        pair<int, int> key = {left, right};

        if (memo.count(key)) {
            return memo[key];
        }

        vector<int> answer;

        for (int i = left; i <= right; i++) {
            char operation = expression[i];

            if (operation != '+' &&
                operation != '-' &&
                operation != '*') {
                continue;
            }

            vector<int> first = solve(expression, left, i - 1, memo);
            vector<int> second = solve(expression, i + 1, right, memo);

            for (int a : first) {
                for (int b : second) {
                    if (operation == '+') {
                        answer.push_back(a + b);
                    } else if (operation == '-') {
                        answer.push_back(a - b);
                    } else {
                        answer.push_back(a * b);
                    }
                }
            }
        }

        if (answer.empty()) {
            answer.push_back(stoi(expression.substr(left, right - left + 1)));
        }

        memo[key] = answer;
        return memo[key];
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        map<pair<int, int>, vector<int>> memo;

        return solve(
            expression,
            0,
            static_cast<int>(expression.size()) - 1,
            memo
        );
    }
};
