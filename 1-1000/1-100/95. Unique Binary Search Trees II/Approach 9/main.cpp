// Approach 9: Catalan ranking and unranking

class Solution {
private:
    vector<long long> catalanCount;

    TreeNode* buildTreeByRank(int startValue,int nodeCount,long long rank) {
        if (nodeCount == 0) {
            return nullptr;
        }

        for (int leftNodeCount = 0; leftNodeCount < nodeCount; leftNodeCount++) {
            int rightNodeCount = nodeCount - leftNodeCount - 1;

            long long leftTreeCount = catalanCount[leftNodeCount];

            long long rightTreeCount = catalanCount[rightNodeCount];

            long long currentGroupSize = leftTreeCount * rightTreeCount;

            if (rank >= currentGroupSize) {
                rank -= currentGroupSize;
                continue;
            }

            long long leftRank = rank / rightTreeCount;

            long long rightRank = rank % rightTreeCount;

            int rootValue = startValue + leftNodeCount;

            TreeNode* root = new TreeNode(rootValue);

            root->left = buildTreeByRank(startValue,leftNodeCount,leftRank);

            root->right = buildTreeByRank(rootValue + 1,rightNodeCount,rightRank);

            return root;
        }

        return nullptr;
    }

public:
    // O(n^2 * Cn) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        catalanCount.assign(n + 1, 0);
        catalanCount[0] = 1;

        for (int totalNodeCount = 1; totalNodeCount <= n; totalNodeCount++) {
            for (int leftNodeCount = 0; leftNodeCount < totalNodeCount; leftNodeCount++) {
                int rightNodeCount = totalNodeCount - leftNodeCount - 1;

                catalanCount[totalNodeCount] += catalanCount[leftNodeCount] * catalanCount[rightNodeCount];
            }
        }

        vector<TreeNode*> allTrees;

        for (long long rank = 0; rank < catalanCount[n]; rank++) {
            allTrees.push_back(buildTreeByRank(1, n, rank));
        }

        return allTrees;
    }
};