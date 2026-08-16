class Solution {
    string encode(
        const vector<vector<int>>& grid
    ) {
        string state;

        for (const vector<int>& row :
             grid) {
            for (int value :
                 row) {
                state.push_back(
                    static_cast<char>(
                        '0' +
                        value
                    )
                );
            }
        }

        return state;
    }

public:
    int minimumMoves(vector<vector<int>>& grid) {
        string start =
            encode(grid);

        string target(
            9,
            '1'
        );

        if (start == target) {
            return 0;
        }

        queue<string> pending;
        unordered_map<string, int> distance;

        pending.push(start);
        distance[start] = 0;

        array<int, 4> dr = {
            -1,1,0,0
        };

        array<int, 4> dc = {
            0,0,-1,1
        };

        while (!pending.empty()) {
            string state =
                pending.front();

            pending.pop();

            int currentDistance =
                distance[state];

            for (int index = 0; index < 9; index++) {
                if (state[index] == '0') {
                    continue;
                }

                int row =
                    index /
                    3;

                int col =
                    index %
                    3;

                for (int direction = 0;
                     direction < 4;
                     direction++) {
                    int nextRow =
                        row +
                        dr[direction];

                    int nextCol =
                        col +
                        dc[direction];

                    if (nextRow < 0 ||
                        nextRow >= 3 ||
                        nextCol < 0 ||
                        nextCol >= 3) {
                        continue;
                    }

                    int nextIndex =
                        nextRow *
                        3 +
                        nextCol;

                    string next =
                        state;

                    next[index]--;
                    next[nextIndex]++;

                    if (distance.count(next)) {
                        continue;
                    }

                    if (next == target) {
                        return
                            currentDistance +
                            1;
                    }

                    distance[next] =
                        currentDistance +
                        1;

                    pending.push(next);
                }
            }
        }

        return -1;
    }
};
