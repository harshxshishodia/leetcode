class Solution {
public:
    int minimumCost(
        int m,
        int n,
        vector<int>& horizontalCut,
        vector<int>& verticalCut
    ) {
        vector<
            vector<
                vector<
                    vector<int>
                >
            >
        > dp(
            m,
            vector<
                vector<
                    vector<int>
                >
            >(
                m,
                vector<vector<int>>(
                    n,
                    vector<int>(
                        n
                    )
                )
            )
        );

        for (int height = 1;
             height <= m;
             height++) {
            for (int width = 1;
                 width <= n;
                 width++) {
                for (int top = 0;
                     top + height <= m;
                     top++) {
                    int bottom =
                        top +
                        height -
                        1;

                    for (int left = 0;
                         left + width <= n;
                         left++) {
                        int right =
                            left +
                            width -
                            1;

                        if (height == 1 &&
                            width == 1) {
                            continue;
                        }

                        int answer =
                            numeric_limits<int>::max();

                        for (int cut = top;
                             cut < bottom;
                             cut++) {
                            answer = min(
                                answer,
                                horizontalCut[cut] +
                                dp[top][cut][left][right] +
                                dp[cut + 1][bottom][left][right]
                            );
                        }

                        for (int cut = left;
                             cut < right;
                             cut++) {
                            answer = min(
                                answer,
                                verticalCut[cut] +
                                dp[top][bottom][left][cut] +
                                dp[top][bottom][cut + 1][right]
                            );
                        }

                        dp[top][bottom][left][right] =
                            answer;
                    }
                }
            }
        }

        return
            dp[0][m - 1][0][n - 1];
    }
};
