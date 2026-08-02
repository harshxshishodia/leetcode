class Solution {
    struct Node {
        char leftChar;
        char rightChar;
        int violations;
        Node() : leftChar(' '), rightChar(' '), violations(0) {}
    };
    vector<Node> segmentTree;
    int treeSize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        Node res;
        res.leftChar = leftNode.leftChar;
        res.rightChar = rightNode.rightChar;
        res.violations = leftNode.violations + rightNode.violations;
        if (leftNode.rightChar == rightNode.leftChar) {
            res.violations++;
        }
        return res;
    }

    void buildTree(int nodeIndex, int left, int right, const string& s) {
        if (left == right) {
            segmentTree[nodeIndex].leftChar = s[left];
            segmentTree[nodeIndex].rightChar = s[left];
            segmentTree[nodeIndex].violations = 0;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, s);
        buildTree(2 * nodeIndex + 2, mid + 1, right, s);
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    void updateTree(int nodeIndex, int left, int right, int updateIndex, char newChar) {
        if (left == right) {
            segmentTree[nodeIndex].leftChar = newChar;
            segmentTree[nodeIndex].rightChar = newChar;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, newChar);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, newChar);
        }
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    Node queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        if (queryRight <= mid) {
            return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        }
        if (queryLeft > mid) {
            return queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        }
        return mergeNodes(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                          queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        treeSize = s.length();
        segmentTree.assign(4 * treeSize, Node());
        buildTree(0, 0, treeSize - 1, s);

        vector<int> resultAnswers;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                updateTree(0, 0, treeSize - 1, q[1], q[2] + 'a');
            } else if (type == 2) {
                Node queryRes = queryTree(0, 0, treeSize - 1, q[1], q[2]);
                resultAnswers.push_back(queryRes.violations);
            }
        }
        return resultAnswers;
    }
};
