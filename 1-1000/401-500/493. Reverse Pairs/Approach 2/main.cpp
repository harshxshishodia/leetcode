class Solution {
    vector<int> temporary;

    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int middle = left + (right - left) / 2;
        int answer = mergeSort(nums, left, middle) + mergeSort(nums, middle + 1, right);
        int rightIndex = middle + 1;

        for (int leftIndex = left; leftIndex <= middle; leftIndex++) {
            while (rightIndex <= right && (long long)nums[leftIndex] > 2LL * nums[rightIndex])
                rightIndex++;

            answer += rightIndex - middle - 1;
        }

        int first = left;
        int second = middle + 1;
        int index = left;

        while (first <= middle && second <= right) {
            if (nums[first] <= nums[second])
                temporary[index++] = nums[first++];
            else
                temporary[index++] = nums[second++];
        }

        while (first <= middle)
            temporary[index++] = nums[first++];

        while (second <= right)
            temporary[index++] = nums[second++];

        for (int position = left; position <= right; position++)
            nums[position] = temporary[position];

        return answer;
    }

public:
    int reversePairs(vector<int>& nums) {
        temporary.resize(nums.size());
        return mergeSort(nums, 0, nums.size() - 1);
    }
};