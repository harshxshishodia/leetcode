class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMaximum = 0;
        int rightMaximum = 0;
        int water = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMaximum)
                    leftMaximum = height[left];
                else
                    water += leftMaximum - height[left];

                left++;
            } else {
                if (height[right] >= rightMaximum)
                    rightMaximum = height[right];
                else
                    water += rightMaximum - height[right];

                right--;
            }
        }

        return water;
    }
};