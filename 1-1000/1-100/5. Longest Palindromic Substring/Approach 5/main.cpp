class Solution {
public:
    string longestPalindrome(string s) {
        int n = static_cast<int>(s.size());
        vector<int> odd(n);
        int left = 0;
        int right = -1;

        for (int i = 0; i < n; i++) {
            int radius = i > right ? 1 : min(odd[left + right - i], right - i + 1);

            while (i - radius >= 0 &&
                   i + radius < n &&
                   s[i - radius] == s[i + radius]) {
                radius++;
            }

            odd[i] = radius;

            if (i + radius - 1 > right) {
                left = i - radius + 1;
                right = i + radius - 1;
            }
        }

        vector<int> even(n);
        left = 0;
        right = -1;

        for (int i = 0; i < n; i++) {
            int radius = i > right ? 0 : min(even[left + right - i + 1], right - i + 1);

            while (i - radius - 1 >= 0 &&
                   i + radius < n &&
                   s[i - radius - 1] == s[i + radius]) {
                radius++;
            }

            even[i] = radius;

            if (i + radius - 1 > right) {
                left = i - radius;
                right = i + radius - 1;
            }
        }

        int bestStart = 0;
        int bestLength = 1;

        for (int i = 0; i < n; i++) {
            int oddLength = 2 * odd[i] - 1;

            if (oddLength > bestLength) {
                bestLength = oddLength;
                bestStart = i - odd[i] + 1;
            }

            int evenLength = 2 * even[i];

            if (evenLength > bestLength) {
                bestLength = evenLength;
                bestStart = i - even[i];
            }
        }

        return s.substr(bestStart, bestLength);
    }
};
