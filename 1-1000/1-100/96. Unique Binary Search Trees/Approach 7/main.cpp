// Approach 7: Catalan number using the binomial coefficient

class Solution {
public:
    // O(n) | O(1)
    int numTrees(int n) {
        long long middleBinomialCoefficient = 1;

        for (int selectedCount = 1; selectedCount <= n; selectedCount++) {
            middleBinomialCoefficient = middleBinomialCoefficient * (n + selectedCount) / selectedCount;
        }

        long long catalanNumber = middleBinomialCoefficient / (n + 1);

        return static_cast<int>(catalanNumber);
    }
};