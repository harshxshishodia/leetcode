class Solution {
    vector<int> segmentTree;
    int treeSize;

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] = min(segmentTree[nodeIndex], value);
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = min(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return INT_MAX;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return min(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        treeSize = n + 2;
        segmentTree.assign(4 * treeSize, INT_MAX);

        vector<pair<int, int>> pairs;
        for (const auto& p : conflictingPairs) {
            int u = min(p[0], p[1]);
            int v = max(p[0], p[1]);
            pairs.push_back({u, v});
            updateTree(0, 1, n, u, v);
        }

        long long baseValidSubarrays = 0;
        vector<int> minRightBound(n + 2, n + 1);

        for (int l = n; l >= 1; l--) {
            int minR = queryTree(0, 1, n, l, n);
            minRightBound[l] = min(minRightBound[l + 1], minR);
            baseValidSubarrays += (minRightBound[l] - l);
        }

        long long maxExtraSubarrays = 0;
        int m = pairs.size();

        for (int i = 0; i < min(m, 100); i++) {
            // Remove pair i and measure increase in valid subarrays
            segmentTree.assign(4 * treeSize, INT_MAX);
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                updateTree(0, 1, n, pairs[j].first, pairs[j].second);
            }
            long long currentValid = 0;
            int curMinR = n + 1;
            for (int l = n; l >= 1; l--) {
                int minR = queryTree(0, 1, n, l, n);
                curMinR = min(curMinR, minR);
                currentValid += (curMinR - l);
            }
            maxExtraSubarrays = max(maxExtraSubarrays, currentValid - baseValidSubarrays);
        }

        return baseValidSubarrays + maxExtraSubarrays;
    }
};
