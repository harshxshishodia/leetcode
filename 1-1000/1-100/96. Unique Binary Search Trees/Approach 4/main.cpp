// Approach 4: Bottom-up dynamic programming

class Solution {
public:
    // O(n^2) | O(n)
    int numTrees(int n) {
        vector<int> treeCount(n + 1, 0);

        treeCount[0] = 1;

        if (n >= 1) {
            treeCount[1] = 1;
        }

        for (int totalNodeCount = 2; totalNodeCount <= n; totalNodeCount++) {
            for (int rootPosition = 1; rootPosition <= totalNodeCount; rootPosition++) {
                int leftNodeCount = rootPosition - 1;
                int rightNodeCount = totalNodeCount - rootPosition;

                treeCount[totalNodeCount] += treeCount[leftNodeCount] * treeCount[rightNodeCount];
            }
        }

        return treeCount[n];
    }
};