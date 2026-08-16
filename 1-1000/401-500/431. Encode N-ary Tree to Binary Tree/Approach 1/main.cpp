class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) { val = _val; children = _children; }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    TreeNode* encode(Node* root) {
        if (!root) return nullptr;
        TreeNode* binaryRoot = new TreeNode(root->val);
        if (!root->children.empty()) {
            binaryRoot->left = encode(root->children[0]);
        }
        TreeNode* currentSibling = binaryRoot->left;
        for (int i = 1; i < static_cast<int>(root->children.size()); i++) {
            currentSibling->right = encode(root->children[i]);
            currentSibling = currentSibling->right;
        }
        return binaryRoot;
    }

    Node* decode(TreeNode* root) {
        if (!root) return nullptr;
        Node* naryRoot = new Node(root->val);
        TreeNode* currentChild = root->left;
        while (currentChild != nullptr) {
            naryRoot->children.push_back(decode(currentChild));
            currentChild = currentChild->right;
        }
        return naryRoot;
    }
};
