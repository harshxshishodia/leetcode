class Solution {
    int solve(
        const vector<vector<int>>& books,
        int shelfWidth,
        int index,
        vector<int>& memo
    ) {
        if (index == static_cast<int>(books.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int width = 0;
        int height = 0;
        int answer =
            numeric_limits<int>::max();

        for (int end = index;
             end < static_cast<int>(books.size());
             end++) {
            width +=
                books[end][0];

            if (width > shelfWidth) {
                break;
            }

            height = max(
                height,
                books[end][1]
            );

            answer = min(
                answer,
                height +
                solve(
                    books,
                    shelfWidth,
                    end + 1,
                    memo
                )
            );
        }

        memo[index] = answer;
        return memo[index];
    }

public:
    int minHeightShelves(
        vector<vector<int>>& books,
        int shelfWidth
    ) {
        vector<int> memo(
            books.size(),
            -1
        );

        return solve(
            books,
            shelfWidth,
            0,
            memo
        );
    }
};
