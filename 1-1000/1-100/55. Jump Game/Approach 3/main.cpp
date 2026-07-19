class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> reachable(n, false);
        reachable[0] = true;

        for (int index = 0; index < n; index++) {
            if (!reachable[index])
                continue;

            int farthest = min(n - 1, index + nums[index]);

            for (int nextIndex = index + 1; nextIndex <= farthest; nextIndex++)
                reachable[nextIndex] = true;
        }

        return reachable[n - 1];
    }
};