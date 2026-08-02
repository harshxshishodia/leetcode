class Fancy {
    struct SegmentTreeNode {
        long long lazyMultiplier;
        long long lazyAdder;
        long long elementValue;
        SegmentTreeNode() : lazyMultiplier(1), lazyAdder(0), elementValue(0) {}
    };
    vector<SegmentTreeNode> segmentTree;
    int treeSize;
    const long long modVal = 1000000007;

    void pushLazy(int nodeIndex) {
        long long mult = segmentTree[nodeIndex].lazyMultiplier;
        long long add = segmentTree[nodeIndex].lazyAdder;
        if (mult != 1 || add != 0) {
            int leftChild = 2 * nodeIndex + 1;
            int rightChild = 2 * nodeIndex + 2;

            segmentTree[leftChild].elementValue = (segmentTree[leftChild].elementValue * mult + add) % modVal;
            segmentTree[leftChild].lazyMultiplier = (segmentTree[leftChild].lazyMultiplier * mult) % modVal;
            segmentTree[leftChild].lazyAdder = (segmentTree[leftChild].lazyAdder * mult + add) % modVal;

            segmentTree[rightChild].elementValue = (segmentTree[rightChild].elementValue * mult + add) % modVal;
            segmentTree[rightChild].lazyMultiplier = (segmentTree[rightChild].lazyMultiplier * mult) % modVal;
            segmentTree[rightChild].lazyAdder = (segmentTree[rightChild].lazyAdder * mult + add) % modVal;

            segmentTree[nodeIndex].lazyMultiplier = 1;
            segmentTree[nodeIndex].lazyAdder = 0;
        }
    }

    void updateRangeAffine(int nodeIndex, int left, int right, int queryLeft, int queryRight, long long mult, long long add) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            segmentTree[nodeIndex].elementValue = (segmentTree[nodeIndex].elementValue * mult + add) % modVal;
            segmentTree[nodeIndex].lazyMultiplier = (segmentTree[nodeIndex].lazyMultiplier * mult) % modVal;
            segmentTree[nodeIndex].lazyAdder = (segmentTree[nodeIndex].lazyAdder * mult + add) % modVal;
            return;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        updateRangeAffine(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, mult, add);
        updateRangeAffine(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, mult, add);
    }

    void updateSinglePoint(int nodeIndex, int left, int right, int updateIndex, long long value) {
        if (left == right) {
            segmentTree[nodeIndex].elementValue = value;
            segmentTree[nodeIndex].lazyMultiplier = 1;
            segmentTree[nodeIndex].lazyAdder = 0;
            return;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateSinglePoint(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateSinglePoint(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
    }

    long long queryPoint(int nodeIndex, int left, int right, int queryIndex) {
        if (left == right) {
            return segmentTree[nodeIndex].elementValue;
        }
        pushLazy(nodeIndex);
        int mid = left + (right - left) / 2;
        if (queryIndex <= mid) {
            return queryPoint(2 * nodeIndex + 1, left, mid, queryIndex);
        } else {
            return queryPoint(2 * nodeIndex + 2, mid + 1, right, queryIndex);
        }
    }

    int currentLength;

public:
    Fancy() {
        treeSize = 100001;
        segmentTree.assign(4 * treeSize, SegmentTreeNode());
        currentLength = 0;
    }
    void append(int val) {
        updateSinglePoint(0, 0, treeSize - 1, currentLength, val);
        currentLength++;
    }
    void addAll(int inc) {
        if (currentLength > 0) {
            updateRangeAffine(0, 0, treeSize - 1, 0, currentLength - 1, 1, inc);
        }
    }
    void multAll(int m) {
        if (currentLength > 0) {
            updateRangeAffine(0, 0, treeSize - 1, 0, currentLength - 1, m, 0);
        }
    }
    int getIndex(int idx) {
        if (idx >= currentLength) return -1;
        return queryPoint(0, 0, treeSize - 1, idx);
    }
};
