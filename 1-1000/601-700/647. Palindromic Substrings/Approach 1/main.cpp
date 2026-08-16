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
    int countSubstrings(string s) {
        int answer = 0;

        for (int left = 0; left < static_cast<int>(s.size()); left++) {
            for (int right = left; right < static_cast<int>(s.size()); right++) {
                if (isPalindrome(s, left, right)) {
                    answer++;
                }
            }
        }

        return answer;
    }
};
