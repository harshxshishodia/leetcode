class Solution {
    vector<int> leftSegmentTree;
    vector<int> rightSegmentTree;
    int maxRating;
    void updateTree(vector<int>& segmentTree, int nodeIndex, int left, int right, int updateIndex, int value) {
        if (left == right) {
            segmentTree[nodeIndex] += value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateIndex <= mid) {
            updateTree(segmentTree, 2 * nodeIndex + 1, left, mid, updateIndex, value);
        } else {
            updateTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, updateIndex, value);
        }
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }
    int queryTree(vector<int>& segmentTree, int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > queryRight || left > queryRight || right < queryLeft) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return queryTree(segmentTree, 2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               queryTree(segmentTree, 2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }
public:
    int numTeams(vector<int>& rating) {
        if (rating.empty()) return 0;
        maxRating = 0;
        for (int r : rating) {
            maxRating = max(maxRating, r);
        }
        leftSegmentTree.assign(4 * maxRating + 4, 0);
        rightSegmentTree.assign(4 * maxRating + 4, 0);
        for (int r : rating) {
            updateTree(rightSegmentTree, 0, 1, maxRating, r, 1);
        }
        int totalTeams = 0;
        for (int r : rating) {
            updateTree(rightSegmentTree, 0, 1, maxRating, r, -1);
            int lessLeft = queryTree(leftSegmentTree, 0, 1, maxRating, 1, r - 1);
            int greaterLeft = queryTree(leftSegmentTree, 0, 1, maxRating, r + 1, maxRating);
            int lessRight = queryTree(rightSegmentTree, 0, 1, maxRating, 1, r - 1);
            int greaterRight = queryTree(rightSegmentTree, 0, 1, maxRating, r + 1, maxRating);
            totalTeams += lessLeft * greaterRight + greaterLeft * lessRight;
            updateTree(leftSegmentTree, 0, 1, maxRating, r, 1);
        }
        return totalTeams;
    }
};
