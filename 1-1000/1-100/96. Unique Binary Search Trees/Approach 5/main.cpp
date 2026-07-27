// Approach 5: Bottom-up dynamic programming using symmetry

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
            int mirroredPairCount = totalNodeCount / 2;

            for (int leftNodeCount = 0; leftNodeCount < mirroredPairCount; leftNodeCount++) {
                int rightNodeCount = totalNodeCount - leftNodeCount - 1;

                treeCount[totalNodeCount] += 2 * treeCount[leftNodeCount] * treeCount[rightNodeCount];
            }

            if (totalNodeCount % 2 == 1) {
                int middleNodeCount = totalNodeCount / 2;

                treeCount[totalNodeCount] += treeCount[middleNodeCount] * treeCount[middleNodeCount];
            }
        }

        return treeCount[n];
    }
};