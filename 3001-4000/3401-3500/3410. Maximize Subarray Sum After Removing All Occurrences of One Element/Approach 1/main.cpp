class Solution {
    struct Node {
        long long maxSum;
        long long prefixSum;
        long long suffixSum;
        long long totalSum;
        Node(long long val = 0) {
            totalSum = val;
            maxSum = max(0LL, val);
            prefixSum = max(0LL, val);
            suffixSum = max(0LL, val);
        }
    };
    vector<Node> segmentTree;
    int treeSize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        Node res;
        res.totalSum = leftNode.totalSum + rightNode.totalSum;
        res.prefixSum = max(leftNode.prefixSum, leftNode.totalSum + rightNode.prefixSum);
        res.suffixSum = max(rightNode.suffixSum, rightNode.totalSum + leftNode.suffixSum);
        res.maxSum = max({leftNode.maxSum, rightNode.maxSum, leftNode.suffixSum + rightNode.prefixSum});
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

    void updateTree(int nodeIndex, int left, int right, int updateIndex, long long val) {
        if (left == right) {
            segmentTree[nodeIndex] = Node(val);
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

public:
    long long maxSubarraySum(vector<int>& nums) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, Node());
        buildTree(0, 0, n - 1, nums);

        long long overallMax = segmentTree[0].maxSum;
        if (overallMax == 0) {
            overallMax = *max_element(nums.begin(), nums.end());
        }

        unordered_map<int, vector<int>> valIndicesMap;
        for (int i = 0; i < n; i++) {
            valIndicesMap[nums[i]].push_back(i);
        }

        for (auto& entry : valIndicesMap) {
            int val = entry.first;
            if (val >= 0) continue; // Only removing negative elements can increase sum

            for (int idx : entry.second) {
                updateTree(0, 0, n - 1, idx, 0);
            }

            long long newMax = segmentTree[0].maxSum;
            overallMax = max(overallMax, newMax);

            for (int idx : entry.second) {
                updateTree(0, 0, n - 1, idx, val);
            }
        }

        return overallMax;
    }
};
