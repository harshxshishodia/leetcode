class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = static_cast<int>(ratings.size());
        vector<pair<int, int>> sortedRatings(n);

        for (int i = 0; i < n; i++) {
            sortedRatings[i] = {ratings[i], i};
        }

        sort(sortedRatings.begin(), sortedRatings.end());

        vector<int> candies(n, 1);

        for (const auto& [rating, index] : sortedRatings) {
            if (index > 0 && ratings[index] > ratings[index - 1]) {
                candies[index] = max(candies[index], candies[index - 1] + 1);
            }

            if (index < n - 1 && ratings[index] > ratings[index + 1]) {
                candies[index] = max(candies[index], candies[index + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
