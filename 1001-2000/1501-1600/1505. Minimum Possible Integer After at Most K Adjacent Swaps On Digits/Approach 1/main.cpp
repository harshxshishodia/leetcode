class Solution {
    vector<int> segmentTree;
    int treeSize;
    void buildTree(int nodeIndex, int left, int right) {
        if (left == right) {
            segmentTree[nodeIndex] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid);
        buildTree(2 * nodeIndex + 2, mid + 1, right);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }
    void updateTree(int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }
    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }
public:
    string minInteger(string num, int k) {
        int n = num.length();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1);
        vector<queue<int>> digitPositions(10);
        for (int i = 0; i < n; i++) {
            digitPositions[num[i] - '0'].push(i);
        }
        string resultStr = "";
        for (int i = 0; i < n; i++) {
            for (int digit = 0; digit <= 9; digit++) {
                if (!digitPositions[digit].empty()) {
                    int originalIndex = digitPositions[digit].front();
                    int shiftCost = queryTree(0, 0, n - 1, 0, originalIndex - 1);
                    if (shiftCost <= k) {
                        k -= shiftCost;
                        resultStr += to_string(digit);
                        updateTree(0, 0, n - 1, originalIndex, 0);
                        digitPositions[digit].pop();
                        break;
                    }
                }
            }
        }
        return resultStr;
    }
};
