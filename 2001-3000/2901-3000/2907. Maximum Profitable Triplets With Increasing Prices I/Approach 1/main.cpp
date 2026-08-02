class Solution {
    vector<int> segmentTree;
    int treeSize;
    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] = max(segmentTree[nodeIndex], value);
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }
    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return -1;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return max(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }
public:
    int maxProfit(vector<int>& prices, vector<int>& profits) {
        int n = prices.size();
        if (n < 3) return -1;
        vector<int> sortedUniquePrices = prices;
        sort(sortedUniquePrices.begin(), sortedUniquePrices.end());
        sortedUniquePrices.erase(unique(sortedUniquePrices.begin(), sortedUniquePrices.end()), sortedUniquePrices.end());
        treeSize = sortedUniquePrices.size();
        vector<int> maxLeft(n, -1);
        segmentTree.assign(4 * treeSize + 4, -1);
        for (int i = 0; i < n; i++) {
            int rankIndex = lower_bound(sortedUniquePrices.begin(), sortedUniquePrices.end(), prices[i]) - sortedUniquePrices.begin() + 1;
            maxLeft[i] = queryTree(0, 1, treeSize, 1, rankIndex - 1);
            updateTree(0, 1, treeSize, rankIndex, profits[i]);
        }
        vector<int> maxRight(n, -1);
        segmentTree.assign(4 * treeSize + 4, -1);
        for (int i = n - 1; i >= 0; i--) {
            int rankIndex = lower_bound(sortedUniquePrices.begin(), sortedUniquePrices.end(), prices[i]) - sortedUniquePrices.begin() + 1;
            maxRight[i] = queryTree(0, 1, treeSize, rankIndex + 1, treeSize);
            updateTree(0, 1, treeSize, rankIndex, profits[i]);
        }
        int maxTotalProfit = -1;
        for (int i = 0; i < n; i++) {
            if (maxLeft[i] != -1 && maxRight[i] != -1) {
                maxTotalProfit = max(maxTotalProfit, maxLeft[i] + profits[i] + maxRight[i]);
            }
        }
        return maxTotalProfit;
    }
};
