// Approach 3: Recursive counting with memoization

class Solution {
private:
    vector<int> memo;

    int countTrees(int numberOfNodes) {
        if (numberOfNodes <= 1) {
            return 1;
        }

        if (memo[numberOfNodes] != -1) {
            return memo[numberOfNodes];
        }

        int totalTreeCount = 0;

        for (int rootPosition = 1; rootPosition <= numberOfNodes; rootPosition++) {
            int leftNodeCount = rootPosition - 1;
            int rightNodeCount = numberOfNodes - rootPosition;

            int leftTreeCount = countTrees(leftNodeCount);
            int rightTreeCount = countTrees(rightNodeCount);

            totalTreeCount += leftTreeCount * rightTreeCount;
        }

        memo[numberOfNodes] = totalTreeCount;

        return memo[numberOfNodes];
    }

public:
    // O(n^2) | O(n)
    int numTrees(int n) {
        memo.assign(n + 1, -1);
        return countTrees(n);
    }
};