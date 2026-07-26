// Approach 9: Iterative traversal using parent pointers

class Solution {
public:
    // O(n) | O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        if (root == nullptr) {
            return traversal;
        }

        unordered_map<TreeNode*, TreeNode*> parent;
        stack<TreeNode*> nodes;

        parent[root] = nullptr;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* currentNode = nodes.top();
            nodes.pop();

            if (currentNode->left != nullptr) {
                parent[currentNode->left] = currentNode;
                nodes.push(currentNode->left);
            }

            if (currentNode->right != nullptr) {
                parent[currentNode->right] = currentNode;
                nodes.push(currentNode->right);
            }
        }

        TreeNode* previousNode = nullptr;
        TreeNode* currentNode = root;

        while (currentNode != nullptr) {
            TreeNode* nextNode = nullptr;

            if (previousNode == parent[currentNode]) {
                if (currentNode->left != nullptr) {
                    nextNode = currentNode->left;
                } else {
                    traversal.push_back(currentNode->val);

                    if (currentNode->right != nullptr) {
                        nextNode = currentNode->right;
                    } else {
                        nextNode = parent[currentNode];
                    }
                }
            } else if (previousNode == currentNode->left) {
                traversal.push_back(currentNode->val);

                if (currentNode->right != nullptr) {
                    nextNode = currentNode->right;
                } else {
                    nextNode = parent[currentNode];
                }
            } else {
                nextNode = parent[currentNode];
            }

            previousNode = currentNode;
            currentNode = nextNode;
        }

        return traversal;
    }
};