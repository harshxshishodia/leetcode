class Solution {
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();

        for (int length = n; length >= 1; length--) {
            for (int start = 0; start + length <= n; start++) {
                int end = start + length - 1;
                if (isPalindrome(s, start, end)) return s.substr(start, length);
            }
        }

        return "";
    }
};