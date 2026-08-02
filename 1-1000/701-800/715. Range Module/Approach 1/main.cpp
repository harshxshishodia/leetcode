class RangeModule {
    struct SegmentTreeNode {
        int trackedCount;
        int lazyValue; // -1: no lazy, 0: set to 0, 1: set to 1
        SegmentTreeNode* leftChild;
        SegmentTreeNode* rightChild;
        SegmentTreeNode() : trackedCount(0), lazyValue(-1), leftChild(nullptr), rightChild(nullptr) {}
    };
    SegmentTreeNode* rootNode;
    const int maxRangeLimit = 1000000000;
    void pushLazy(SegmentTreeNode* node, int currentStart, int currentEnd) {
        if (node->lazyValue != -1) {
            int mid = currentStart + (currentEnd - currentStart) / 2;
            if (!node->leftChild) node->leftChild = new SegmentTreeNode();
            if (!node->rightChild) node->rightChild = new SegmentTreeNode();
            node->leftChild->lazyValue = node->lazyValue;
            node->leftChild->trackedCount = node->lazyValue * (mid - currentStart + 1);
            node->rightChild->lazyValue = node->lazyValue;
            node->rightChild->trackedCount = node->lazyValue * (currentEnd - mid);
            node->lazyValue = -1;
        }
    }
    void updateRange(SegmentTreeNode* node, int currentStart, int currentEnd, int queryStart, int queryEnd, int setValue) {
        if (currentStart > queryEnd || currentEnd < queryStart) {
            return;
        }
        if (currentStart >= queryStart && currentEnd <= queryEnd) {
            node->lazyValue = setValue;
            node->trackedCount = setValue * (currentEnd - currentStart + 1);
            return;
        }
        pushLazy(node, currentStart, currentEnd);
        int mid = currentStart + (currentEnd - currentStart) / 2;
        if (!node->leftChild) node->leftChild = new SegmentTreeNode();
        if (!node->rightChild) node->rightChild = new SegmentTreeNode();
        updateRange(node->leftChild, currentStart, mid, queryStart, queryEnd, setValue);
        updateRange(node->rightChild, mid + 1, currentEnd, queryStart, queryEnd, setValue);
        node->trackedCount = node->leftChild->trackedCount + node->rightChild->trackedCount;
    }
    int queryRangeCount(SegmentTreeNode* node, int currentStart, int currentEnd, int queryStart, int queryEnd) {
        if (!node || currentStart > queryEnd || currentEnd < queryStart) {
            return 0;
        }
        if (currentStart >= queryStart && currentEnd <= queryEnd) {
            return node->trackedCount;
        }
        pushLazy(node, currentStart, currentEnd);
        int mid = currentStart + (currentEnd - currentStart) / 2;
        return queryRangeCount(node->leftChild, currentStart, mid, queryStart, queryEnd) +
               queryRangeCount(node->rightChild, mid + 1, currentEnd, queryStart, queryEnd);
    }
public:
    RangeModule() {
        rootNode = new SegmentTreeNode();
    }
    void addRange(int left, int right) {
        updateRange(rootNode, 1, maxRangeLimit, left, right - 1, 1);
    }
    bool queryRange(int left, int right) {
        int count = queryRangeCount(rootNode, 1, maxRangeLimit, left, right - 1);
        return count == (right - left);
    }
    void removeRange(int left, int right) {
        updateRange(rootNode, 1, maxRangeLimit, left, right - 1, 0);
    }
};
