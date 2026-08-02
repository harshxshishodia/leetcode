class Solution {
    struct Node {
        int prefixLength;
        int suffixLength;
        int maxRepeatLength;
        char leftChar;
        char rightChar;
        int nodeLength;
        Node() : prefixLength(0), suffixLength(0), maxRepeatLength(0), leftChar(' '), rightChar(' '), nodeLength(0) {}
    };
    vector<Node> segmentTree;
    int treeSize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        Node resultNode;
        resultNode.leftChar = leftNode.leftChar;
        resultNode.rightChar = rightNode.rightChar;
        resultNode.nodeLength = leftNode.nodeLength + rightNode.nodeLength;

        resultNode.prefixLength = leftNode.prefixLength;
        if (leftNode.prefixLength == leftNode.nodeLength && leftNode.rightChar == rightNode.leftChar) {
            resultNode.prefixLength = leftNode.nodeLength + rightNode.prefixLength;
        }

        resultNode.suffixLength = rightNode.suffixLength;
        if (rightNode.suffixLength == rightNode.nodeLength && leftNode.rightChar == rightNode.leftChar) {
            resultNode.suffixLength = rightNode.nodeLength + leftNode.suffixLength;
        }

        resultNode.maxRepeatLength = max(leftNode.maxRepeatLength, rightNode.maxRepeatLength);
        if (leftNode.rightChar == rightNode.leftChar) {
            resultNode.maxRepeatLength = max(resultNode.maxRepeatLength, leftNode.suffixLength + rightNode.prefixLength);
        }

        return resultNode;
    }

    void buildTree(int nodeIndex, int left, int right, const string& s) {
        if (left == right) {
            segmentTree[nodeIndex].prefixLength = 1;
            segmentTree[nodeIndex].suffixLength = 1;
            segmentTree[nodeIndex].maxRepeatLength = 1;
            segmentTree[nodeIndex].leftChar = s[left];
            segmentTree[nodeIndex].rightChar = s[left];
            segmentTree[nodeIndex].nodeLength = 1;
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

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        treeSize = s.length();
        segmentTree.assign(4 * treeSize, Node());
        buildTree(0, 0, treeSize - 1, s);
        vector<int> resultLengths;
        int numQueries = queryIndices.size();
        for (int i = 0; i < numQueries; i++) {
            updateTree(0, 0, treeSize - 1, queryIndices[i], queryCharacters[i]);
            resultLengths.push_back(segmentTree[0].maxRepeatLength);
        }
        return resultLengths;
    }
};
