class LUPrefix {
    vector<bool> segmentTree;
    int treeSize;
    void updateTree(int nodeIndex, int left, int right, int updateIndex) {
        if (left == right) {
            segmentTree[nodeIndex] = true;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] && segmentTree[2 * nodeIndex + 2];
    }
    int queryLongestPrefix(int nodeIndex, int left, int right) {
        if (segmentTree[nodeIndex]) {
            return right;
        }
        if (left == right) {
            return left - 1;
        }
        int mid = left + (right - left) / 2;
        if (segmentTree[2 * nodeIndex + 1]) {
            int rightResult = queryLongestPrefix(2 * nodeIndex + 2, mid + 1, right);
            return rightResult;
        } else {
            return queryLongestPrefix(2 * nodeIndex + 1, left, mid);
        }
    }
public:
    LUPrefix(int n) {
        treeSize = n;
        segmentTree.assign(4 * treeSize + 4, false);
    }
    void upload(int video) {
        updateTree(0, 1, treeSize, video);
    }
    int longest() {
        return queryLongestPrefix(0, 1, treeSize);
    }
};
