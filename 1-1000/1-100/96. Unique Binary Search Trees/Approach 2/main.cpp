// Approach 2: Pure recursive counting

class Solution {
private:
    int countTrees(int numberOfNodes) {
        if (numberOfNodes <= 1) {
            return 1;
        }

        int totalTreeCount = 0;

        for (int rootPosition = 1; rootPosition <= numberOfNodes; rootPosition++) {
            int leftNodeCount = rootPosition - 1;
            int rightNodeCount = numberOfNodes - rootPosition;

            int leftTreeCount = countTrees(leftNodeCount);
            int rightTreeCount = countTrees(rightNodeCount);

            totalTreeCount += leftTreeCount * rightTreeCount;
        }

        return totalTreeCount;
    }

public:
    // O(3^n) | O(n)
    int numTrees(int n) {
        return countTrees(n);
    }
};