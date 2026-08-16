class Solution {
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        int n = static_cast<int>(s.size());
        vector<vector<string>> answer;
        int cutPositions = n - 1;
        int totalMasks = 1 << cutPositions;

        for (int mask = 0; mask < totalMasks; mask++) {
            vector<string> current;
            int start = 0;
            bool valid = true;

            for (int position = 0; position < n; position++) {
                bool makeCut = position == n - 1 ||
                               ((mask & (1 << position)) != 0);

                if (!makeCut) {
                    continue;
                }

                if (!isPalindrome(s, start, position)) {
                    valid = false;
                    break;
                }

                current.push_back(s.substr(start, position - start + 1));
                start = position + 1;
            }

            if (valid) {
                answer.push_back(current);
            }
        }

        return answer;
    }
};
