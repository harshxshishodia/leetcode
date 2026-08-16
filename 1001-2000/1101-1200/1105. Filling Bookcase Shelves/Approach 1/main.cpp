class Solution {
    int solve(
        const vector<vector<int>>& books,
        int shelfWidth,
        int index
    ) {
        if (index == static_cast<int>(books.size())) {
            return 0;
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
                    end + 1
                )
            );
        }

        return answer;
    }

public:
    int minHeightShelves(
        vector<vector<int>>& books,
        int shelfWidth
    ) {
        return solve(
            books,
            shelfWidth,
            0
        );
    }
};
