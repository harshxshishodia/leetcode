class Solution {
    vector<int> segmentTree;
    int treeSize;
    void buildTree(int nodeIndex, int left, int right, const vector<int>& baskets) {
        if (left == right) {
            segmentTree[nodeIndex] = baskets[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, baskets);
        buildTree(2 * nodeIndex + 2, mid + 1, right, baskets);
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }
    int placeFruit(int nodeIndex, int left, int right, int requiredCapacity) {
        if (segmentTree[nodeIndex] < requiredCapacity) {
            return -1;
        }
        if (left == right) {
            segmentTree[nodeIndex] = -1;
            return left;
        }
        int mid = left + (right - left) / 2;
        int placedIndex = -1;
        if (segmentTree[2 * nodeIndex + 1] >= requiredCapacity) {
            placedIndex = placeFruit(2 * nodeIndex + 1, left, mid, requiredCapacity);
        } else {
            placedIndex = placeFruit(2 * nodeIndex + 2, mid + 1, right, requiredCapacity);
        }
        segmentTree[nodeIndex] = max(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
        return placedIndex;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        treeSize = baskets.size();
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, treeSize - 1, baskets);
        int unplacedCount = 0;
        for (int fruitQuantity : fruits) {
            int basketIndex = placeFruit(0, 0, treeSize - 1, fruitQuantity);
            if (basketIndex == -1) {
                unplacedCount++;
            }
        }
        return unplacedCount;
    }
};
