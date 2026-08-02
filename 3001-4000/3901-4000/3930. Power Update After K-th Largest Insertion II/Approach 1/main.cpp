class Solution {
    vector<int> segmentTree;
    int treeSize;

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] += value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    int findKthLargest(int nodeIndex, int left, int right, int k) {
        if (left == right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        int rightCount = segmentTree[2 * nodeIndex + 2];
        if (rightCount >= k) {
            return findKthLargest(2 * nodeIndex + 2, mid + 1, right, k);
        } else {
            return findKthLargest(2 * nodeIndex + 1, left, mid, k - rightCount);
        }
    }

    long long modularExponentiation(long long baseVal, long long expVal, long long modVal) {
        long long resultVal = 1;
        baseVal %= modVal;
        while (expVal > 0) {
            if (expVal % 2 == 1) {
                resultVal = (resultVal * baseVal) % modVal;
            }
            baseVal = (baseVal * baseVal) % modVal;
            expVal /= 2;
        }
        return resultVal;
    }

public:
    vector<int> processQueries(vector<int>& nums, int p, vector<vector<int>>& queries) {
        vector<int> sortedUniqueNums = nums;
        for (const auto& query : queries) {
            sortedUniqueNums.push_back(query[0]);
        }
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        treeSize = sortedUniqueNums.size();
        segmentTree.assign(4 * treeSize, 0);

        for (int num : nums) {
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), num) - sortedUniqueNums.begin() + 1;
            updateTree(0, 1, treeSize, rankIndex, 1);
        }

        vector<int> answer;
        long long currentP = p;
        long long modVal = 1000000007;

        for (const auto& query : queries) {
            int val = query[0];
            int k = query[1];
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), val) - sortedUniqueNums.begin() + 1;
            updateTree(0, 1, treeSize, rankIndex, 1);

            int kthRank = findKthLargest(0, 1, treeSize, k);
            int kthValue = sortedUniqueNums[kthRank - 1];

            currentP = modularExponentiation(currentP, kthValue, modVal);
            answer.push_back(currentP);
        }

        return answer;
    }
};
