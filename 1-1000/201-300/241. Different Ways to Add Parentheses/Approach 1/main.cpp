class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> answer;

        for (int i = 0; i < static_cast<int>(expression.size()); i++) {
            char operation = expression[i];

            if (operation != '+' &&
                operation != '-' &&
                operation != '*') {
                continue;
            }

            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));

            for (int first : left) {
                for (int second : right) {
                    if (operation == '+') {
                        answer.push_back(first + second);
                    } else if (operation == '-') {
                        answer.push_back(first - second);
                    } else {
                        answer.push_back(first * second);
                    }
                }
            }
        }

        if (answer.empty()) {
            answer.push_back(stoi(expression));
        }

        return answer;
    }
};
