class Solution {
    vector<int> answer;
    vector<int> indices;
    vector<int> temporary;

    void mergeSort(const vector<int>& nums, int left, int right) {
        if (left >= right)
            return;

        int middle = left + (right - left) / 2;
        mergeSort(nums, left, middle);
        mergeSort(nums, middle + 1, right);

        int first = left;
        int second = middle + 1;
        int position = left;

        while (first <= middle && second <= right) {
            if (nums[indices[first]] <= nums[indices[second]]) {
                answer[indices[first]] += second - middle - 1;
                temporary[position] = indices[first];
                first++;
            } else {
                temporary[position] = indices[second];
                second++;
            }

            position++;
        }

        while (first <= middle) {
            answer[indices[first]] += second - middle - 1;
            temporary[position] = indices[first];
            first++;
            position++;
        }

        while (second <= right) {
            temporary[position] = indices[second];
            second++;
            position++;
        }

        for (int index = left; index <= right; index++)
            indices[index] = temporary[index];
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        answer.assign(n, 0);
        indices.resize(n);
        temporary.resize(n);

        for (int index = 0; index < n; index++)
            indices[index] = index;

        mergeSort(nums, 0, n - 1);
        return answer;
    }
};