class Solution {
    vector<int> tree1;
    vector<int> tree2;
    int treeSize;

    void updateTree(vector<int>& segmentTree, int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] += value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(segmentTree, 2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    int queryTree(const vector<int>& segmentTree, int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(segmentTree, 2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedUniqueNums = nums;
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        treeSize = sortedUniqueNums.size();

        tree1.assign(4 * treeSize, 0);
        tree2.assign(4 * treeSize, 0);

        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};

        int rank1 = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[0]) - sortedUniqueNums.begin() + 1;
        int rank2 = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[1]) - sortedUniqueNums.begin() + 1;
        updateTree(tree1, 0, 1, treeSize, rank1, 1);
        updateTree(tree2, 0, 1, treeSize, rank2, 1);

        for (int i = 2; i < n; i++) {
            int rankVal = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), nums[i]) - sortedUniqueNums.begin() + 1;
            int count1 = queryTree(tree1, 0, 1, treeSize, rankVal + 1, treeSize);
            int count2 = queryTree(tree2, 0, 1, treeSize, rankVal + 1, treeSize);

            if (count1 > count2) {
                arr1.push_back(nums[i]);
                updateTree(tree1, 0, 1, treeSize, rankVal, 1);
            } else if (count1 < count2) {
                arr2.push_back(nums[i]);
                updateTree(tree2, 0, 1, treeSize, rankVal, 1);
            } else if (arr1.size() <= arr2.size()) {
                arr1.push_back(nums[i]);
                updateTree(tree1, 0, 1, treeSize, rankVal, 1);
            } else {
                arr2.push_back(nums[i]);
                updateTree(tree2, 0, 1, treeSize, rankVal, 1);
            }
        }

        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
