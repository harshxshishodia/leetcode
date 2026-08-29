class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        if (n <= 1) {
            return n;
        }

        int totalCandies = 1;
        int up = 0;
        int down = 0;
        int peak = 0;

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                up++;
                peak = up;
                down = 0;
                totalCandies += 1 + up;
            } else if (ratings[i] == ratings[i - 1]) {
                up = 0;
                down = 0;
                peak = 0;
                totalCandies += 1;
            } else {
                down++;
                up = 0;
                totalCandies += down + (down > peak ? 1 : 0);
            }
        }

        return totalCandies;
    }
};
