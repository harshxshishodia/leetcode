class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;

        for (char character : s) {
            if (character == 'b') {
                bCount++;
            } else {
                deletions = min(
                    deletions + 1,
                    bCount
                );
            }
        }

        return deletions;
    }
};
