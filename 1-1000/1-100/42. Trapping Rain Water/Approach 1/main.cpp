class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        for (int index = 0; index < n; index++) {
            int leftMaximum = 0;
            int rightMaximum = 0;

            for (int left = index; left >= 0; left--)
                leftMaximum = max(leftMaximum, height[left]);

            for (int right = index; right < n; right++)
                rightMaximum = max(rightMaximum, height[right]);

            water += min(leftMaximum, rightMaximum) - height[index];
        }

        return water;
    }
};