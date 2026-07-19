class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        stack<int> indices;

        for (int index = 0; index < n; index++) {
            while (!indices.empty() && height[index] > height[indices.top()]) {
                int bottom = indices.top();
                indices.pop();

                if (indices.empty())
                    break;

                int left = indices.top();
                int width = index - left - 1;
                int boundedHeight = min(height[left], height[index]) - height[bottom];
                water += width * boundedHeight;
            }

            indices.push(index);
        }

        return water;
    }
};