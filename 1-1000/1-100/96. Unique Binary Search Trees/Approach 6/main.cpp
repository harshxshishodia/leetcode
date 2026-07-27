// Approach 6: Catalan number multiplicative recurrence

class Solution {
public:
    // O(n) | O(1)
    int numTrees(int n) {
        long long catalanNumber = 1;

        for (int nodeCount = 0; nodeCount < n; nodeCount++) {
            catalanNumber = catalanNumber * 2 * (2 * nodeCount + 1) / (nodeCount + 2);
        }

        return static_cast<int>(catalanNumber);
    }
};