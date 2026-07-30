// Approach 3: Compare inorder traversal with its sorted copy

class Solution {
private:
    void collectInorderNodes(
        TreeNode* currentNode,
        vector<TreeNode*>& inorderNodes
    ) {
        if (currentNode == nullptr) {
            return;
        }

        collectInorderNodes(
            currentNode->left,
            inorderNodes
        );

        inorderNodes.push_back(currentNode);

        collectInorderNodes(
            currentNode->right,
            inorderNodes
        );
    }

public:
    // O(n log n) | O(n)
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorderNodes;

        collectInorderNodes(
            root,
            inorderNodes
        );

        vector<int> sortedValues;

        for (TreeNode* currentNode : inorderNodes) {
            sortedValues.push_back(currentNode->val);
        }

        sort(
            sortedValues.begin(),
            sortedValues.end()
        );

        TreeNode* firstSwappedNode = nullptr;
        TreeNode* secondSwappedNode = nullptr;

        for (
            int index = 0;
            index < inorderNodes.size();
            index++
        ) {
            if (
                inorderNodes[index]->val !=
                sortedValues[index]
            ) {
                if (firstSwappedNode == nullptr) {
                    firstSwappedNode = inorderNodes[index];
                } else {
                    secondSwappedNode = inorderNodes[index];
                }
            }
        }

        swap(
            firstSwappedNode->val,
            secondSwappedNode->val
        );
    }
};