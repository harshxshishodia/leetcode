struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
    vector<TreeNode*> treeNodes;

public:
    CBTInserter(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (!bfsQueue.empty()) {
            TreeNode* current = bfsQueue.front();
            bfsQueue.pop();
            treeNodes.push_back(current);
            if (current->left) bfsQueue.push(current->left);
            if (current->right) bfsQueue.push(current->right);
        }
    }

    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        treeNodes.push_back(newNode);
        int parentIndex = (treeNodes.size() - 2) / 2;
        TreeNode* parentNode = treeNodes[parentIndex];
        if (treeNodes.size() % 2 == 0) {
            parentNode->left = newNode;
        } else {
            parentNode->right = newNode;
        }
        return parentNode->val;
    }

    TreeNode* get_root() {
        return treeNodes.empty() ? nullptr : treeNodes[0];
    }
};
