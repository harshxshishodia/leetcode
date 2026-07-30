// Approach 4: Store inorder nodes and detect the two inversions

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
    // O(n) | O(n)
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorderNodes;

        collectInorderNodes(
            root,
            inorderNodes
        );

        TreeNode* firstSwappedNode = nullptr;
        TreeNode* secondSwappedNode = nullptr;

        for (
            int index = 1;
            index < inorderNodes.size();
            index++
        ) {
            if (
                inorderNodes[index - 1]->val >
                inorderNodes[index]->val
            ) {
                if (firstSwappedNode == nullptr) {
                    firstSwappedNode = inorderNodes[index - 1];
                }

                secondSwappedNode = inorderNodes[index];
            }
        }

        swap(
            firstSwappedNode->val,
            secondSwappedNode->val
        );
    }
};