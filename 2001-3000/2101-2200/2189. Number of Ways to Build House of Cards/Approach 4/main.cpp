class Solution {
public:
    int houseOfCards(int n) {
        vector<int> dp(
            n + 1
        );

        dp[0] = 1;

        for (int rowCards = 2;
             rowCards <= n;
             rowCards += 3) {
            for (int cards = n;
                 cards >= rowCards;
                 cards--) {
                dp[cards] +=
                    dp[cards - rowCards];
            }
        }

        return dp[n];
    }
};
