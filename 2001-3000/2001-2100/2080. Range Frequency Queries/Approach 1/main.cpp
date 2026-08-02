class RangeFreqQuery {
    vector<vector<int>> segmentTree;
    int arraySize;
    void buildTree(int nodeIndex, int left, int right, const vector<int>& arr) {
        if (left == right) {
            segmentTree[nodeIndex].push_back(arr[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, arr);
        buildTree(2 * nodeIndex + 2, mid + 1, right, arr);
        merge(segmentTree[2 * nodeIndex + 1].begin(), segmentTree[2 * nodeIndex + 1].end(),
              segmentTree[2 * nodeIndex + 2].begin(), segmentTree[2 * nodeIndex + 2].end(),
              back_inserter(segmentTree[nodeIndex]));
    }
    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight, int targetValue) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (queryLeft <= left && queryRight >= right) {
            auto lowerBoundIt = lower_bound(segmentTree[nodeIndex].begin(), segmentTree[nodeIndex].end(), targetValue);
            auto upperBoundIt = upper_bound(segmentTree[nodeIndex].begin(), segmentTree[nodeIndex].end(), targetValue);
            return distance(lowerBoundIt, upperBoundIt);
        }
        int mid = left + (right - left) / 2;
        return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, targetValue) +
               queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, targetValue);
    }
public:
    RangeFreqQuery(vector<int>& arr) {
        arraySize = arr.size();
        segmentTree.assign(4 * arraySize, vector<int>());
        buildTree(0, 0, arraySize - 1, arr);
    }
    int query(int left, int right, int value) {
        return queryTree(0, 0, arraySize - 1, left, right, value);
    }
};
