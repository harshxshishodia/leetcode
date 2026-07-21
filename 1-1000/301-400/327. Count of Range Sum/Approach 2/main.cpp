class Solution {
    long long mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1)
            return 0;

        int middle = left + (right - left) / 2;
        long long answer = mergeSort(prefix, left, middle, lower, upper) + mergeSort(prefix, middle, right, lower, upper);
        int lowerIndex = middle;
        int upperIndex = middle;

        for (int index = left; index < middle; index++) {
            while (lowerIndex < right && prefix[lowerIndex] - prefix[index] < lower)
                lowerIndex++;

            while (upperIndex < right && prefix[upperIndex] - prefix[index] <= upper)
                upperIndex++;

            answer += upperIndex - lowerIndex;
        }

        inplace_merge(prefix.begin() + left, prefix.begin() + middle, prefix.begin() + right);
        return answer;
    }

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int index = 0; index < n; index++)
            prefix[index + 1] = prefix[index] + nums[index];

        return mergeSort(prefix, 0, n + 1, lower, upper);
    }
};