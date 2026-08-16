class Solution {
public:
    int maxResult(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> dp(n);

        priority_queue<pair<int, int>> heap;

        dp[0] = nums[0];
        heap.push({
            dp[0],
            0
        });

        for (int index = 1;
             index < n;
             index++) {
            while (heap.top().second <
                   index - k) {
                heap.pop();
            }

            dp[index] =
                nums[index] +
                heap.top().first;

            heap.push({
                dp[index],
                index
            });
        }

        return dp[n - 1];
    }
};
