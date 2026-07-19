class Solution {
    bool isValid(const string& current) {
        int balance = 0;

        for (char character : current) {
            if (character == '(')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return balance == 0;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int length = 2 * n;
        int total = 1 << length;

        for (int mask = 0; mask < total; mask++) {
            string current;

            for (int index = 0; index < length; index++) {
                if (mask & (1 << index))
                    current.push_back('(');
                else
                    current.push_back(')');
            }

            if (isValid(current))
                result.push_back(current);
        }

        return result;
    }
};