class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        vector<vector<bool>> visited(
            n + 1,
            vector<bool>(n + 1)
        );

        queue<pair<int, int>> pending;
        pending.push({1, 0});
        visited[1][0] = true;
        int steps = 0;

        while (!pending.empty()) {
            int levelSize = static_cast<int>(pending.size());

            for (int i = 0; i < levelSize; i++) {
                auto [screen, clipboard] = pending.front();
                pending.pop();

                if (screen == n) {
                    return steps;
                }

                if (clipboard > 0 &&
                    screen + clipboard <= n &&
                    !visited[screen + clipboard][clipboard]) {
                    visited[screen + clipboard][clipboard] = true;
                    pending.push({
                        screen + clipboard,
                        clipboard
                    });
                }

                if (clipboard != screen &&
                    !visited[screen][screen]) {
                    visited[screen][screen] = true;
                    pending.push({
                        screen,
                        screen
                    });
                }
            }

            steps++;
        }

        return steps;
    }
};
