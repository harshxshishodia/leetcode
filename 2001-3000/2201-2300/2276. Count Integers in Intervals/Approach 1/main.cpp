class CountIntervals {
    struct SegmentTreeNode {
        int trackedCount;
        int lazyValue;
        SegmentTreeNode* leftChild;
        SegmentTreeNode* rightChild;
        SegmentTreeNode() : trackedCount(0), lazyValue(0), leftChild(nullptr), rightChild(nullptr) {}
    };
    SegmentTreeNode* rootNode;
    const int maxRangeLimit = 1000000000;
    void pushLazy(SegmentTreeNode* node, int currentStart, int currentEnd) {
        if (node->lazyValue == 1) {
            int mid = currentStart + (currentEnd - currentStart) / 2;
            if (!node->leftChild) node->leftChild = new SegmentTreeNode();
            if (!node->rightChild) node->rightChild = new SegmentTreeNode();
            node->leftChild->lazyValue = 1;
            node->leftChild->trackedCount = (mid - currentStart + 1);
            node->rightChild->lazyValue = 1;
            node->rightChild->trackedCount = (currentEnd - mid);
            node->lazyValue = 0;
        }
    }
    void updateRange(SegmentTreeNode* node, int currentStart, int currentEnd, int queryStart, int queryEnd) {
        if (currentStart > queryEnd || currentEnd < queryStart) {
            return;
        }
        if (currentStart >= queryStart && currentEnd <= queryEnd) {
            node->lazyValue = 1;
            node->trackedCount = (currentEnd - currentStart + 1);
            return;
        }
        pushLazy(node, currentStart, currentEnd);
        int mid = currentStart + (currentEnd - currentStart) / 2;
        if (!node->leftChild) node->leftChild = new SegmentTreeNode();
        if (!node->rightChild) node->rightChild = new SegmentTreeNode();
        updateRange(node->leftChild, currentStart, mid, queryStart, queryEnd);
        updateRange(node->rightChild, mid + 1, currentEnd, queryStart, queryEnd);
        node->trackedCount = node->leftChild->trackedCount + node->rightChild->trackedCount;
    }
public:
    CountIntervals() {
        rootNode = new SegmentTreeNode();
    }
    void add(int left, int right) {
        updateRange(rootNode, 1, maxRangeLimit, left, right);
    }
    int count() {
        return rootNode->trackedCount;
    }
};
