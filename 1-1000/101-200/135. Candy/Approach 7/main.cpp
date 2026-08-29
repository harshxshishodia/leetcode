class Solution {
    int count(int n) {
        return (n * (n + 1)) / 2;
    }

public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        if (n <= 1) {
            return n;
        }

        int totalCandies = 0;
        int up = 0;
        int down = 0;
        int oldSlope = 0;

        for (int i = 1; i < n; i++) {
            int newSlope = (ratings[i] > ratings[i - 1]) ? 1 : (ratings[i] < ratings[i - 1] ? -1 : 0);

            if ((oldSlope > 0 && newSlope == 0) || (oldSlope < 0 && newSlope >= 0)) {
                totalCandies += count(up) + count(down) + max(up, down);
                up = 0;
                down = 0;
            }

            if (newSlope > 0) {
                up++;
            } else if (newSlope < 0) {
                down++;
            } else {
                totalCandies++;
            }

            oldSlope = newSlope;
        }

        totalCandies += count(up) + count(down) + max(up, down) + 1;

        return totalCandies;
    }
};
