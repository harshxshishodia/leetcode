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
    int getPermutationIndex(vector<int>& perm) {
        int n = perm.size();
        treeSize = n;
        segmentTree.assign(4 * treeSize + 4, 0);
        buildTree(0, 1, treeSize);
        long long MOD = 1000000007;
        vector<long long> factorial(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
        long long permutationIndex = 0;
        for (int i = 0; i < n; i++) {
            int currentElement = perm[i];
            int availableSmaller = queryTree(0, 1, treeSize, 1, currentElement - 1);
            long long ways = (availableSmaller * factorial[n - 1 - i]) % MOD;
            permutationIndex = (permutationIndex + ways) % MOD;
            updateTree(0, 1, treeSize, currentElement, 0);
        }
        return permutationIndex;
    }
    int findIndex(vector<int>& perm) { return getPermutationIndex(perm); }
    int findPermutationIndex(vector<int>& perm) { return getPermutationIndex(perm); }
};
