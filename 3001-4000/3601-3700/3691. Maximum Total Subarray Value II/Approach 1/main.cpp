class Solution {
    struct Node {
        long long maxVal;
        long long sumVal;
        Node(long long v = 0) : maxVal(v), sumVal(v) {}
    };
    vector<Node> segmentTree;
    int treeSize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        Node res;
        res.maxVal = max(leftNode.maxVal, rightNode.maxVal);
        res.sumVal = leftNode.sumVal + rightNode.sumVal;
        return res;
    }

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums) {
        if (left == right) {
            segmentTree[nodeIndex] = Node(nums[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums);
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] = Node(value);
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    Node queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return Node(LLONG_MIN / 2);
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return mergeNodes(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                          queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    long long maxSubarrayValue(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, Node());
        buildTree(0, 0, n - 1, nums);

        long long totalMaxVal = 0;
        for (const auto& q : queries) {
            updateTree(0, 0, n - 1, q[0], q[1]);
            totalMaxVal += max(0LL, segmentTree[0].maxVal);
        }
        return totalMaxVal;
    }
};
