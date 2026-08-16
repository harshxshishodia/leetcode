class Solution {
    int solve(
        const vector<int>& rows,
        int index,
        int remaining
    ) {
        if (remaining == 0) {
            return 1;
        }

        if (index == static_cast<int>(rows.size()) ||
            remaining < 0) {
            return 0;
        }

        return
            solve(
                rows,
                index + 1,
                remaining
            ) +
            solve(
                rows,
                index + 1,
                remaining - rows[index]
            );
    }

public:
    int houseOfCards(int n) {
        vector<int> rows;

        for (int cards = 2;
             cards <= n;
             cards += 3) {
            rows.push_back(cards);
        }

        return solve(
            rows,
            0,
            n
        );
    }
};
