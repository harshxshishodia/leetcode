class Solution {
    struct Node {
        int length;
        int count;
        Node(int l = 0, int c = 0) : length(l), count(c) {}
    };
    Node mergeNodes(Node leftNode, Node rightNode) {
        if (leftNode.length == rightNode.length) {
            if (leftNode.length == 0) return Node(0, 0);
            return Node(leftNode.length, leftNode.count + rightNode.count);
        }
        return leftNode.length > rightNode.length ? leftNode : rightNode;
    }
    vector<Node> segmentTree;
    int treeSize;
    void updateTree(int nodeIndex, int left, int right, int updateIndex, Node val) {
        if (left == right) {
            segmentTree[nodeIndex] = mergeNodes(segmentTree[nodeIndex], val);
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, val);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, val);
        }
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }
    Node queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (left > queryRight || right < queryLeft) {
            return Node(0, 0);
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        Node leftResult = queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        Node rightResult = queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        return mergeNodes(leftResult, rightResult);
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> sortedUniqueNums = nums;
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        sortedUniqueNums.erase(unique(sortedUniqueNums.begin(), sortedUniqueNums.end()), sortedUniqueNums.end());
        treeSize = sortedUniqueNums.size();
        segmentTree.assign(4 * treeSize, Node());
        for (int num : nums) {
            int rankIndex = lower_bound(sortedUniqueNums.begin(), sortedUniqueNums.end(), num) - sortedUniqueNums.begin() + 1;
            Node bestPrevious = queryTree(0, 1, treeSize, 1, rankIndex - 1);
            Node currentNode;
            if (bestPrevious.length == 0) {
                currentNode = Node(1, 1);
            } else {
                currentNode = Node(bestPrevious.length + 1, bestPrevious.count);
            }
            updateTree(0, 1, treeSize, rankIndex, currentNode);
        }
        Node overallBest = queryTree(0, 1, treeSize, 1, treeSize);
        return overallBest.count;
    }
};
