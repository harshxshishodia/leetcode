class Solution {
    vector<long long> segmentTree;
    vector<long long> lazyTree;
    int treeSize;

    void pushLazy(int nodeIndex, int left, int right) {
        if (lazyTree[nodeIndex] != -1) {
            long long val = lazyTree[nodeIndex];
            int mid = left + (right - left) / 2;

            segmentTree[2 * nodeIndex + 1] = val * (mid - left + 1);
            lazyTree[2 * nodeIndex + 1] = val;

            segmentTree[2 * nodeIndex + 2] = val * (right - mid);
            lazyTree[2 * nodeIndex + 2] = val;

            lazyTree[nodeIndex] = -1;
        }
    }

    void updateRangeSet(int nodeIndex, int left, int right, int queryLeft, int queryRight, long long val) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            segmentTree[nodeIndex] = val * (right - left + 1);
            lazyTree[nodeIndex] = val;
            return;
        }
        pushLazy(nodeIndex, left, right);
        int mid = left + (right - left) / 2;
        updateRangeSet(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, val);
        updateRangeSet(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, val);
        segmentTree[nodeIndex] = segmentTree[2 * nodeIndex + 1] + segmentTree[2 * nodeIndex + 2];
    }

    long long querySum(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        pushLazy(nodeIndex, left, right);
        int mid = left + (right - left) / 2;
        return querySum(2 * nodeIndex + 1, left, mid, queryLeft, queryRight) +
               querySum(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
    }

public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        lazyTree.assign(4 * treeSize, -1);

        vector<long long> origPrefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            origPrefix[i + 1] = origPrefix[i] + nums[i];
            updateRangeSet(0, 0, n - 1, i, i, nums[i]);
        }

        long long totalSubarrays = 0;
        deque<int> monoDeque; // Stores indices of monotonic max
        int left = n - 1;

        for (int right = n - 1; right >= 0; right--) {
            while (!monoDeque.empty() && nums[monoDeque.back()] < nums[right]) {
                monoDeque.pop_back();
            }
            int nextGreater = monoDeque.empty() ? left + 1 : monoDeque.back();
            monoDeque.push_back(right);

            updateRangeSet(0, 0, n - 1, right, nextGreater - 1, nums[right]);

            while (left >= right) {
                long long modifiedSum = querySum(0, 0, n - 1, right, left);
                long long originalSum = origPrefix[left + 1] - origPrefix[right];
                long long opsNeeded = modifiedSum - originalSum;

                if (opsNeeded <= k) {
                    break;
                }
                left--;
            }

            totalSubarrays += (left - right + 1);
        }

        return totalSubarrays;
    }
};
