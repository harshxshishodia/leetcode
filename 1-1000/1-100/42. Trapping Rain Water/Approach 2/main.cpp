class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMaximum(n);
        vector<int> rightMaximum(n);
        int water = 0;

        leftMaximum[0] = height[0];

        for (int index = 1; index < n; index++)
            leftMaximum[index] = max(leftMaximum[index - 1], height[index]);

        rightMaximum[n - 1] = height[n - 1];

        for (int index = n - 2; index >= 0; index--)
            rightMaximum[index] = max(rightMaximum[index + 1], height[index]);

        for (int index = 0; index < n; index++)
            water += min(leftMaximum[index], rightMaximum[index]) - height[index];

        return water;
    }
};