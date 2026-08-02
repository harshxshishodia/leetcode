class Solution {
    struct Node {
        long long dp[2][2];
        Node() {
            dp[0][0] = 0; dp[0][1] = 0;
            dp[1][0] = 0; dp[1][1] = 0;
        }
    };
    vector<Node> segmentTree;
    int treeSize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        Node res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.dp[i][j] = max({
                    leftNode.dp[i][0] + rightNode.dp[0][j],
                    leftNode.dp[i][0] + rightNode.dp[1][j],
                    leftNode.dp[i][1] + rightNode.dp[0][j]
                });
            }
        }
        return res;
    }

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums) {
        if (left == right) {
            segmentTree[nodeIndex].dp[0][0] = 0;
            segmentTree[nodeIndex].dp[0][1] = 0;
            segmentTree[nodeIndex].dp[1][0] = 0;
            segmentTree[nodeIndex].dp[1][1] = max(0, nums[left]);
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums);
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex].dp[1][1] = max(0, value);
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

public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, Node());
        buildTree(0, 0, n - 1, nums);

        long long totalMaxSum = 0;
        long long modVal = 1000000007;

        for (const auto& q : queries) {
            updateTree(0, 0, n - 1, q[0], q[1]);
            long long bestForQuery = max({
                segmentTree[0].dp[0][0],
                segmentTree[0].dp[0][1],
                segmentTree[0].dp[1][0],
                segmentTree[0].dp[1][1]
            });
            totalMaxSum = (totalMaxSum + bestForQuery) % modVal;
        }

        return totalMaxSum;
    }
};
