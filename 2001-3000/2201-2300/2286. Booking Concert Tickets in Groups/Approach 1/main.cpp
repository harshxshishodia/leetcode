class BookMyShow {
    struct Node {
        long long maxSeats;
        long long sumSeats;
        Node(long long maxS = 0, long long sumS = 0) : maxSeats(maxS), sumSeats(sumS) {}
    };
    vector<Node> segmentTree;
    int totalRows;
    int rowCapacity;

    void buildTree(int nodeIndex, int left, int right) {
        if (left == right) {
            segmentTree[nodeIndex] = Node(rowCapacity, rowCapacity);
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid);
        buildTree(2 * nodeIndex + 2, mid + 1, right);
        segmentTree[nodeIndex].maxSeats = max(segmentTree[2 * nodeIndex + 1].maxSeats, segmentTree[2 * nodeIndex + 2].maxSeats);
        segmentTree[nodeIndex].sumSeats = segmentTree[2 * nodeIndex + 1].sumSeats + segmentTree[2 * nodeIndex + 2].sumSeats;
    }

    void updateSeat(int nodeIndex, int left, int right, int updateRow, long long newCount) {
        if (left == right) {
            segmentTree[nodeIndex].maxSeats = newCount;
            segmentTree[nodeIndex].sumSeats = newCount;
            return;
        }
        int mid = left + (right - left) / 2;
        if (updateRow <= mid) {
            updateSeat(2 * nodeIndex + 1, left, mid, updateRow, newCount);
        } else {
            updateSeat(2 * nodeIndex + 2, mid + 1, right, updateRow, newCount);
        }
        segmentTree[nodeIndex].maxSeats = max(segmentTree[2 * nodeIndex + 1].maxSeats, segmentTree[2 * nodeIndex + 2].maxSeats);
        segmentTree[nodeIndex].sumSeats = segmentTree[2 * nodeIndex + 1].sumSeats + segmentTree[2 * nodeIndex + 2].sumSeats;
    }

    int findGatherRow(int nodeIndex, int left, int right, int maxRow, int k) {
        if (left > maxRow || segmentTree[nodeIndex].maxSeats < k) {
            return -1;
        }
        if (left == right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        int leftRes = findGatherRow(2 * nodeIndex + 1, left, mid, maxRow, k);
        if (leftRes != -1) return leftRes;
        return findGatherRow(2 * nodeIndex + 2, mid + 1, right, maxRow, k);
    }

    long long querySum(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex].sumSeats;
        }
        int mid = left + (right - left) / 2;
        return querySum(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               querySum(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

    void consumeSeats(int nodeIndex, int left, int right, int maxRow, long long& k, vector<long long>& rowAvailable) {
        if (left > maxRow || k == 0 || segmentTree[nodeIndex].sumSeats == 0) {
            return;
        }
        if (left == right) {
            long long take = min(k, rowAvailable[left]);
            rowAvailable[left] -= take;
            k -= take;
            segmentTree[nodeIndex].maxSeats = rowAvailable[left];
            segmentTree[nodeIndex].sumSeats = rowAvailable[left];
            return;
        }
        int mid = left + (right - left) / 2;
        consumeSeats(2 * nodeIndex + 1, left, mid, maxRow, k, rowAvailable);
        if (k > 0) {
            consumeSeats(2 * nodeIndex + 2, mid + 1, right, maxRow, k, rowAvailable);
        }
        segmentTree[nodeIndex].maxSeats = max(segmentTree[2 * nodeIndex + 1].maxSeats, segmentTree[2 * nodeIndex + 2].maxSeats);
        segmentTree[nodeIndex].sumSeats = segmentTree[2 * nodeIndex + 1].sumSeats + segmentTree[2 * nodeIndex + 2].sumSeats;
    }

    vector<long long> rowAvailableSeats;

public:
    BookMyShow(int n, int m) {
        totalRows = n;
        rowCapacity = m;
        segmentTree.assign(4 * totalRows, Node());
        rowAvailableSeats.assign(totalRows, rowCapacity);
        buildTree(0, 0, totalRows - 1);
    }

    vector<int> gather(int k, int maxRow) {
        int targetRow = findGatherRow(0, 0, totalRows - 1, maxRow, k);
        if (targetRow == -1) return {};
        int startSeatIndex = rowCapacity - rowAvailableSeats[targetRow];
        rowAvailableSeats[targetRow] -= k;
        updateSeat(0, 0, totalRows - 1, targetRow, rowAvailableSeats[targetRow]);
        return {targetRow, startSeatIndex};
    }

    bool scatter(int k, int maxRow) {
        long long availableSum = querySum(0, 0, totalRows - 1, 0, maxRow);
        if (availableSum < k) return false;
        long long remainingToScatter = k;
        consumeSeats(0, 0, totalRows - 1, maxRow, remainingToScatter, rowAvailableSeats);
        return true;
    }
};
