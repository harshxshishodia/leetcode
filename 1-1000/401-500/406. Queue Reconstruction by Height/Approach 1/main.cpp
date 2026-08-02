class Solution {
    vector<int> segmentTree;
    void buildSegmentTree(int nodeIndex, int left, int right) {
        if (left == right) {
            segmentTree[nodeIndex] = 1;
            return;
        }
        int mid = left + (right - left) / 2;
        buildSegmentTree(2 * nodeIndex + 1, left, mid);
        buildSegmentTree(2 * nodeIndex + 2, mid + 1, right);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }
    int queryAndPlace(int nodeIndex, int left, int right, int emptySpotsNeeded) {
        segmentTree[nodeIndex]--;
        if (left == right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if (segmentTree[2 * nodeIndex + 1] >= emptySpotsNeeded) {
            return queryAndPlace(2 * nodeIndex + 1, left, mid, emptySpotsNeeded);
        } else {
            return queryAndPlace(2 * nodeIndex + 2, mid + 1, right, emptySpotsNeeded - segmentTree[2 * nodeIndex + 1]);
        }
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int numPeople = people.size();
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        segmentTree.assign(4 * numPeople, 0);
        buildSegmentTree(0, 0, numPeople - 1);
        vector<vector<int>> reconstructedQueue(numPeople, vector<int>(2, 0));
        for (const vector<int>& person : people) {
            int targetIndex = queryAndPlace(0, 0, numPeople - 1, person[1] + 1);
            reconstructedQueue[targetIndex] = person;
        }
        return reconstructedQueue;
    }
};
