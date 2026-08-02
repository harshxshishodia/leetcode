class Solution {
    struct Node {
        int prefixOnes;
        int suffixOnes;
        int maxSection;
        int nodeLen;
        Node() : prefixOnes(0), suffixOnes(0), maxSection(0), nodeLen(0) {}
    };
    vector<Node> segmentTree;
    int treeSize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        Node res;
        res.nodeLen = leftNode.nodeLen + rightNode.nodeLen;

        res.prefixOnes = leftNode.prefixOnes;
        if (leftNode.prefixOnes == leftNode.nodeLen) {
            res.prefixOnes = leftNode.nodeLen + rightNode.prefixOnes;
        }

        res.suffixOnes = rightNode.suffixOnes;
        if (rightNode.suffixOnes == rightNode.nodeLen) {
            res.suffixOnes = rightNode.nodeLen + leftNode.suffixOnes;
        }

        res.maxSection = max({leftNode.maxSection, rightNode.maxSection, leftNode.suffixOnes + rightNode.prefixOnes});
        return res;
    }

    void buildTree(int nodeIndex, int left, int right, const string& s) {
        if (left == right) {
            int val = (s[left] == '1') ? 1 : 0;
            segmentTree[nodeIndex].prefixOnes = val;
            segmentTree[nodeIndex].suffixOnes = val;
            segmentTree[nodeIndex].maxSection = val;
            segmentTree[nodeIndex].nodeLen = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, s);
        buildTree(2 * nodeIndex + 2, mid + 1, right, s);
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    void updateTree(int nodeIndex, int left, int right, int updateIndex, char val) {
        if (left == right) {
            int bitVal = (val == '1') ? 1 : 0;
            segmentTree[nodeIndex].prefixOnes = bitVal;
            segmentTree[nodeIndex].suffixOnes = bitVal;
            segmentTree[nodeIndex].maxSection = bitVal;
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
    vector<int> maxActiveSections(string s, vector<vector<int>>& queries) {
        treeSize = s.length();
        segmentTree.assign(4 * treeSize, Node());
        buildTree(0, 0, treeSize - 1, s);

        vector<int> resultAnswers;
        for (const auto& q : queries) {
            updateTree(0, 0, treeSize - 1, q[0], q[1] + '0');
            resultAnswers.push_back(segmentTree[0].maxSection);
        }
        return resultAnswers;
    }
};
