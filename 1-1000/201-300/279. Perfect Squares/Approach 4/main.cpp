class Solution {
public:
    int numSquares(int n) {
        vector<bool> visited(n + 1);
        queue<int> pending;
        pending.push(n);
        visited[n] = true;
        int steps = 0;

        while (!pending.empty()) {
            int levelSize = static_cast<int>(pending.size());
            steps++;

            for (int i = 0; i < levelSize; i++) {
                int current = pending.front();
                pending.pop();

                for (int value = 1; value * value <= current; value++) {
                    int next = current - value * value;

                    if (next == 0) {
                        return steps;
                    }

                    if (!visited[next]) {
                        visited[next] = true;
                        pending.push(next);
                    }
                }
            }
        }

        return steps;
    }
};
