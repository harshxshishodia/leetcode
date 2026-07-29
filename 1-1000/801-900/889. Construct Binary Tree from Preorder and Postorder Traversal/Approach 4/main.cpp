// Approach 4: Iterative construction using a stack

class Solution {
public:
    // O(n) | O(h)
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        stack<TreeNode*> unfinishedNodes;
        unfinishedNodes.push(root);

        int postorderIndex = 0;

        for (int preorderIndex = 1; preorderIndex < preorder.size(); preorderIndex++) {
            while (
                !unfinishedNodes.empty() &&
                unfinishedNodes.top()->val == postorder[postorderIndex]
            ) {
                unfinishedNodes.pop();
                postorderIndex++;
            }

            TreeNode* currentNode = new TreeNode(preorder[preorderIndex]);
            TreeNode* parentNode = unfinishedNodes.top();

            if (parentNode->left == nullptr) {
                parentNode->left = currentNode;
            } else {
                parentNode->right = currentNode;
            }

            unfinishedNodes.push(currentNode);
        }

        return root;
    }
};