class Solution {
public:
    int orderOfLargestPlusSign(
        int n,
        vector<vector<int>>& mines
    ) {
        unordered_set<int> blocked;

        for (const vector<int>& mine : mines) {
            blocked.insert(
                mine[0] * n + mine[1]
            );
        }

        int answer = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (blocked.count(row * n + col)) {
                    continue;
                }

                int order = 1;

                while (true) {
                    int distance = order;

                    if (row - distance < 0 ||
                        row + distance >= n ||
                        col - distance < 0 ||
                        col + distance >= n) {
                        break;
                    }

                    if (blocked.count(
                            (row - distance) * n + col) ||
                        blocked.count(
                            (row + distance) * n + col) ||
                        blocked.count(
                            row * n + col - distance) ||
                        blocked.count(
                            row * n + col + distance)) {
                        break;
                    }

                    order++;
                }

                answer = max(answer, order);
            }
        }

        return answer;
    }
};
