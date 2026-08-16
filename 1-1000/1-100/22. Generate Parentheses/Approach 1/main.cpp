class Solution {
    bool valid(const string& current) {
        int balance = 0;

        for (char character : current) {
            if (character == '(') {
                balance++;
            } else {
                balance--;
            }

            if (balance < 0) {
                return false;
            }
        }

        return balance == 0;
    }

    void generate(int n, string& current, vector<string>& answer) {
        if (static_cast<int>(current.size()) == 2 * n) {
            if (valid(current)) {
                answer.push_back(current);
            }

            return;
        }

        current.push_back('(');
        generate(n, current, answer);
        current.pop_back();

        current.push_back(')');
        generate(n, current, answer);
        current.pop_back();
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string current;
        generate(n, current, answer);
        return answer;
    }
};
