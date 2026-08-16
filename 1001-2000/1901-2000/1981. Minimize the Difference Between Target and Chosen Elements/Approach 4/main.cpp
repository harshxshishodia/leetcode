class Solution {
public:
    int minimizeTheDifference(
        vector<vector<int>>& mat,
        int target
    ) {
        bitset<5001> possible;
        possible[0] = 1;

        for (const vector<int>& row : mat) {
            bitset<5001> next;

            for (int value : row) {
                next |=
                    possible << value;
            }

            possible = next;
        }

        int answer =
            numeric_limits<int>::max();

        for (int sum = 0; sum <= 5000; sum++) {
            if (possible[sum]) {
                answer = min(
                    answer,
                    abs(
                        sum - target
                    )
                );
            }
        }

        return answer;
    }
};
