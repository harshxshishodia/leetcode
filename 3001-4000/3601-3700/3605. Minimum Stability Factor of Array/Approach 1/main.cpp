class Solution {
    vector<int> segmentTree;
    int treeSize;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    void buildTree(int nodeIndex, int left, int right, const vector<int>& nums) {
        if (left == right) {
            segmentTree[nodeIndex] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, nums);
        buildTree(2 * nodeIndex + 2, mid + 1, right, nums);
        segmentTree[nodeIndex] = gcd(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    int queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return 0;
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        int leftGcd = queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight);
        int rightGcd = queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight);
        return gcd(leftGcd, rightGcd);
    }

public:
    int minStabilityFactor(vector<int>& nums, int maxOps) {
        int n = nums.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize, 0);
        buildTree(0, 0, n - 1, nums);

        int low = 0, high = n, bestStability = n;

        auto checkValid = [&](int targetLen) {
            if (targetLen == 0) return true;
            int requiredOps = 0;
            int i = 0;
            while (i <= n - targetLen) {
                int currentGcd = queryTree(0, 0, n - 1, i, i + targetLen - 1);
                if (currentGcd > 1) {
                    requiredOps++;
                    i += targetLen;
                } else {
                    i++;
                }
            }
            return requiredOps <= maxOps;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkValid(mid)) {
                bestStability = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return bestStability;
    }
};
