struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void serializeHelper(TreeNode* root, stringstream& ss) {
        if (!root) return;
        ss << root->val << " ";
        serializeHelper(root->left, ss);
        serializeHelper(root->right, ss);
    }

    TreeNode* deserializeHelper(vector<int>& values, int& index, int minVal, int maxVal) {
        if (index >= static_cast<int>(values.size()) || values[index] < minVal || values[index] > maxVal) {
            return nullptr;
        }
        int val = values[index++];
        TreeNode* root = new TreeNode(val);
        root->left = deserializeHelper(values, index, minVal, val);
        root->right = deserializeHelper(values, index, val, maxVal);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeHelper(root, ss);
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        vector<int> values;
        int val;
        while (ss >> val) {
            values.push_back(val);
        }
        int index = 0;
        return deserializeHelper(values, index, INT_MIN, INT_MAX);
    }
};
