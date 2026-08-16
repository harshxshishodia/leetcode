class Solution {
public:
    int houseOfCards(int n) {
        vector<int> rows;

        for (int cards = 2;
             cards <= n;
             cards += 3) {
            rows.push_back(cards);
        }

        int count =
            static_cast<int>(rows.size());

        vector<vector<int>> dp(
            count + 1,
            vector<int>(
                n + 1
            )
        );

        dp[0][0] = 1;

        for (int index = 1;
             index <= count;
             index++) {
            for (int cards = 0;
                 cards <= n;
                 cards++) {
                dp[index][cards] =
                    dp[index - 1][cards];

                if (cards >= rows[index - 1]) {
                    dp[index][cards] +=
                        dp[index - 1][
                            cards -
                            rows[index - 1]
                        ];
                }
            }
        }

        return dp[count][n];
    }
};
