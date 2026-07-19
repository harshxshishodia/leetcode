class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        queue<int> indices;
        vector<bool> visited(n, false);
        indices.push(0);
        visited[0] = true;

        int jumps = 0;

        while (!indices.empty()) {
            int levelSize = indices.size();
            jumps++;

            while (levelSize > 0) {
                int index = indices.front();
                indices.pop();
                levelSize--;

                for (int nextIndex = index + 1; nextIndex <= index + nums[index] && nextIndex < n; nextIndex++) {
                    if (nextIndex == n - 1)
                        return jumps;

                    if (!visited[nextIndex]) {
                        visited[nextIndex] = true;
                        indices.push(nextIndex);
                    }
                }
            }
        }

        return -1;
    }
};