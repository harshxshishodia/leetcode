class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        vector<bool> visited(amount + 1);
        queue<int> pending;
        pending.push(0);
        visited[0] = true;
        int steps = 0;

        while (!pending.empty()) {
            int levelSize = static_cast<int>(pending.size());
            steps++;

            for (int i = 0; i < levelSize; i++) {
                int current = pending.front();
                pending.pop();

                for (int coin : coins) {
                    int next = current + coin;

                    if (next == amount) {
                        return steps;
                    }

                    if (next < amount && !visited[next]) {
                        visited[next] = true;
                        pending.push(next);
                    }
                }
            }
        }

        return -1;
    }
};
