class BookMyShow {
    int totalRows, rowCapacity;
    vector<long long> treeSum;
    vector<int> treeMax;

    void update(int node, int start, int end, int index, int val) {
        if (start == end) {
            treeSum[node] = val;
            treeMax[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid) update(2 * node, start, mid, index, val);
        else update(2 * node + 1, mid + 1, end, index, val);
        treeSum[node] = treeSum[2 * node] + treeSum[2 * node + 1];
        treeMax[node] = max(treeMax[2 * node], treeMax[2 * node + 1]);
    }

    int findFirstRowWithMax(int node, int start, int end, int maxRow, int requiredSeats) {
        if (treeMax[node] < requiredSeats || start > maxRow) return -1;
        if (start == end) return start;
        int mid = start + (end - start) / 2;
        int res = findFirstRowWithMax(2 * node, start, mid, maxRow, requiredSeats);
        if (res != -1) return res;
        return findFirstRowWithMax(2 * node + 1, mid + 1, end, maxRow, requiredSeats);
    }

    long long querySum(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return treeSum[node];
        int mid = start + (end - start) / 2;
        return querySum(2 * node, start, mid, l, r) + querySum(2 * node + 1, mid + 1, end, l, r);
    }

    vector<int> availableSeats;
    int firstAvailableRow;

public:
    BookMyShow(int n, int m)
        : totalRows(n), rowCapacity(m), treeSum(4 * n, 0), treeMax(4 * n, 0), availableSeats(n, m), firstAvailableRow(0) {
        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, i, m);
        }
    }

    vector<int> gather(int k, int maxRow) {
        int r = findFirstRowWithMax(1, 0, totalRows - 1, maxRow, k);
        if (r == -1) return {};
        int seat = rowCapacity - availableSeats[r];
        availableSeats[r] -= k;
        update(1, 0, totalRows - 1, r, availableSeats[r]);
        return {r, seat};
    }

    bool scatter(int k, int maxRow) {
        long long availableSum = querySum(1, 0, totalRows - 1, 0, maxRow);
        if (availableSum < k) return false;

        while (k > 0) {
            int take = min(k, availableSeats[firstAvailableRow]);
            availableSeats[firstAvailableRow] -= take;
            k -= take;
            update(1, 0, totalRows - 1, firstAvailableRow, availableSeats[firstAvailableRow]);
            if (availableSeats[firstAvailableRow] == 0) {
                firstAvailableRow++;
            }
        }
        return true;
    }
};
