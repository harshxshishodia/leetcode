class Solution {
public:
    int longestString(
        int x,
        int y,
        int z
    ) {
        int blocks =
            2 *
            min(
                x,
                y
            ) +
            z;

        if (x != y) {
            blocks++;
        }

        return
            2 *
            blocks;
    }
};
