class Solution {
public:
    int jump(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<bool> visited(n);
        queue<pair<int, int>> pending;
        pending.push({0, 0});
        visited[0] = true;

        while (!pending.empty()) {
            int index = pending.front().first;
            int jumps = pending.front().second;
            pending.pop();

            if (index == n - 1) {
                return jumps;
            }

            int furthest = min(n - 1, index + nums[index]);

            for (int next = index + 1; next <= furthest; next++) {
                if (!visited[next]) {
                    visited[next] = true;
                    pending.push({next, jumps + 1});
                }
            }
        }

        return 0;
    }
};
