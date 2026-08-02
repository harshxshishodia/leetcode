class MyCalendarTwo {
    struct SegmentTreeNode {
        int maximumOverlaps;
        int lazyValue;
        SegmentTreeNode* leftChild;
        SegmentTreeNode* rightChild;
        SegmentTreeNode() : maximumOverlaps(0), lazyValue(0), leftChild(nullptr), rightChild(nullptr) {}
    };
    SegmentTreeNode* rootNode;
    const int maxTime = 1e9;
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
        if (!node->leftChild) {
            node->leftChild = new SegmentTreeNode();
        }
        if (!node->rightChild) {
            node->rightChild = new SegmentTreeNode();
        }
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
    int queryTree(SegmentTreeNode* node, int currentStart, int currentEnd, int queryStart, int queryEnd) {
        if (!node || currentStart > queryEnd || currentEnd < queryStart) {
            return 0;
        }
        if (currentStart >= queryStart && currentEnd <= queryEnd) {
            return node->maximumOverlaps;
        }
        int midTime = currentStart + (currentEnd - currentStart) / 2;
        if (node->lazyValue != 0) {
            if (!node->leftChild) node->leftChild = new SegmentTreeNode();
            if (!node->rightChild) node->rightChild = new SegmentTreeNode();
            node->leftChild->maximumOverlaps += node->lazyValue;
            node->leftChild->lazyValue += node->lazyValue;
            node->rightChild->maximumOverlaps += node->lazyValue;
            node->rightChild->lazyValue += node->lazyValue;
            node->lazyValue = 0;
        }
        int leftMax = queryTree(node->leftChild, currentStart, midTime, queryStart, queryEnd);
        int rightMax = queryTree(node->rightChild, midTime + 1, currentEnd, queryStart, queryEnd);
        return max(leftMax, rightMax);
    }
public:
    MyCalendarTwo() {
        rootNode = new SegmentTreeNode();
    }
    bool book(int startTime, int endTime) {
        int currentOverlaps = queryTree(rootNode, 0, maxTime, startTime, endTime - 1);
        if (currentOverlaps >= 2) {
            return false;
        }
        updateTree(rootNode, 0, maxTime, startTime, endTime - 1, 1);
        return true;
    }
};
