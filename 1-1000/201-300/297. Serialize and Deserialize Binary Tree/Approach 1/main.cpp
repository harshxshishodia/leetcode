struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void serializeDfs(TreeNode* root, stringstream& ss) {
        if (!root) {
            ss << "# ";
            return;
        }
        ss << root->val << " ";
        serializeDfs(root->left, ss);
        serializeDfs(root->right, ss);
    }

    TreeNode* deserializeDfs(stringstream& ss) {
        string token;
        if (!(ss >> token)) return nullptr;
        if (token == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeDfs(ss);
        root->right = deserializeDfs(ss);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDfs(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDfs(ss);
    }
};
