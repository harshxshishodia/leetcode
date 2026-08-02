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
        if (queryLeft > right || queryRight < left) {
            return -1;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return max(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                   queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

    struct QueryInfo {
        int minX;
        int minY;
        int originalIndex;
        bool operator<(const QueryInfo& other) const {
            return minX > other.minX;
        }
    };

    struct ElementInfo {
        int xVal;
        int yVal;
        int sumVal;
        bool operator<(const ElementInfo& other) const {
            return xVal > other.xVal;
        }
    };

public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<ElementInfo> elements(n);
        vector<int> sortedUniqueY = nums2;
        for (const auto& q : queries) {
            sortedUniqueY.push_back(q[1]);
        }
        sort(sortedUniqueY.begin(), sortedUniqueY.end());
        sortedUniqueY.erase(unique(sortedUniqueY.begin(), sortedUniqueY.end()), sortedUniqueY.end());

        for (int i = 0; i < n; i++) {
            elements[i] = {nums1[i], nums2[i], nums1[i] + nums2[i]};
        }
        sort(elements.begin(), elements.end());

        int numQueries = queries.size();
        vector<QueryInfo> sortedQueries(numQueries);
        for (int i = 0; i < numQueries; i++) {
            sortedQueries[i] = {queries[i][0], queries[i][1], i};
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        treeSize = sortedUniqueY.size();
        segmentTree.assign(4 * treeSize, -1);

        vector<int> queryAnswers(numQueries, -1);
        int elementIndex = 0;

        for (const auto& query : sortedQueries) {
            while (elementIndex < n && elements[elementIndex].xVal >= query.minX) {
                int yRank = lower_bound(sortedUniqueY.begin(), sortedUniqueY.end(), elements[elementIndex].yVal) - sortedUniqueY.begin() + 1;
                updateTree(0, 1, treeSize, yRank, elements[elementIndex].sumVal);
                elementIndex++;
            }
            int minYRank = lower_bound(sortedUniqueY.begin(), sortedUniqueY.end(), query.minY) - sortedUniqueY.begin() + 1;
            queryAnswers[query.originalIndex] = queryTree(0, 1, treeSize, minYRank, treeSize);
        }

        return queryAnswers;
    }
};
