class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        vector<int> left2Right(n, 1);
        vector<int> right2Left(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left2Right[i] = left2Right[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right2Left[i] = right2Left[i + 1] + 1;
            }
        }

        int totalCandies = 0;
        for (int i = 0; i < n; i++) {
            totalCandies += max(left2Right[i], right2Left[i]);
        }

        return totalCandies;
    }
};
