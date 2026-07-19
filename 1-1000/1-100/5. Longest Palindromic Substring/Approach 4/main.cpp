class Solution {
public:
    // O(n) | O(n)
    string longestPalindrome(string s) {
        string transformed = "^";

        for (char character : s) {
            transformed += '#';
            transformed += character;
        }

        transformed += "#$";

        int n = transformed.size();
        vector<int> radius(n, 0);
        int center = 0;
        int right = 0;
        int bestCenter = 0;
        int bestRadius = 0;

        for (int index = 1; index < n - 1; index++) {
            int mirror = 2 * center - index;

            if (index < right) radius[index] = min(right - index, radius[mirror]);

            while (transformed[index + radius[index] + 1] == transformed[index - radius[index] - 1]) radius[index]++;

            if (index + radius[index] > right) {
                center = index;
                right = index + radius[index];
            }

            if (radius[index] > bestRadius) {
                bestRadius = radius[index];
                bestCenter = index;
            }
        }

        int start = (bestCenter - bestRadius) / 2;
        return s.substr(start, bestRadius);
    }
};