class Solution {
public:
    bool checkValidString(string s) {
        int minimumOpen = 0;
        int maximumOpen = 0;

        for (char character : s) {
            if (character == '(') {
                minimumOpen++;
                maximumOpen++;
            } else if (character == ')') {
                minimumOpen--;
                maximumOpen--;
            } else {
                minimumOpen--;
                maximumOpen++;
            }

            if (maximumOpen < 0) {
                return false;
            }

            minimumOpen = max(
                minimumOpen,
                0
            );
        }

        return minimumOpen == 0;
    }
};
