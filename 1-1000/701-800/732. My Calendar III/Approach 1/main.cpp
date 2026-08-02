class MyCalendarThree {
    struct SegmentTreeNode {
        int maximumOverlaps;
        int lazyValue;
        SegmentTreeNode* leftChild;
        SegmentTreeNode* rightChild;
        SegmentTreeNode() : maximumOverlaps(0), lazyValue(0), leftChild(nullptr), rightChild(nullptr) {}
    };
    SegmentTreeNode* rootNode;
    const int maxTimeLimit = 1000000000;
    void updateTree(SegmentTreeNode* node, int currentStart, int currentEnd, int queryStart, int queryEnd, int value) {
        if (currentStart > queryEnd || currentEnd < queryStart) {
            return;
        }
        if (currentStart >= queryStart && currentEnd <= queryEnd) {
            node->maximumOverlaps += value;
            node->lazyValue += value;
            return;
        }
        int midTime = currentStart + (currentEnd - currentStart) / 2;
        if (!node->leftChild) node->leftChild = new SegmentTreeNode();
        if (!node->rightChild) node->rightChild = new SegmentTreeNode();
        if (node->lazyValue != 0) {
            node->leftChild->maximumOverlaps += node->lazyValue;
            node->leftChild->lazyValue += node->lazyValue;
            node->rightChild->maximumOverlaps += node->lazyValue;
            node->rightChild->lazyValue += node->lazyValue;
            node->lazyValue = 0;
        }
        updateTree(node->leftChild, currentStart, midTime, queryStart, queryEnd, value);
        updateTree(node->rightChild, midTime + 1, currentEnd, queryStart, queryEnd, value);
        node->maximumOverlaps = max(node->leftChild->maximumOverlaps, node->rightChild->maximumOverlaps);
    }
public:
    MyCalendarThree() {
        rootNode = new SegmentTreeNode();
    }
    int book(int startTime, int endTime) {
        updateTree(rootNode, 0, maxTimeLimit, startTime, endTime - 1, 1);
        return rootNode->maximumOverlaps;
    }
};
