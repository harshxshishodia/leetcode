class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0;
        int bCount = 0;

        for (char character : s) {
            if (character == 'b') {
                bCount++;
                continue;
            }

            if (bCount > 0) {
                deletions++;
                bCount--;
            }
        }

        return deletions;
    }
};
