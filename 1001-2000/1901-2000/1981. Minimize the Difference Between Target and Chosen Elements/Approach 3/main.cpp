class Solution {
public:
    int minimizeTheDifference(
        vector<vector<int>>& mat,
        int target
    ) {
        unordered_set<int> possible = {
            0
        };

        for (const vector<int>& row : mat) {
            unordered_set<int> next;

            for (int sum : possible) {
                for (int value : row) {
                    next.insert(
                        sum + value
                    );
                }
            }

            possible = move(next);
        }

        int answer =
            numeric_limits<int>::max();

        for (int sum : possible) {
            answer = min(
                answer,
                abs(
                    sum - target
                )
            );
        }

        return answer;
    }
};
