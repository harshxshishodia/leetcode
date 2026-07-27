// Approach 7: Canonical subtree identification

class Solution {
private:
    struct SubtreeKey {
        int value;
        int leftSubtreeId;
        int rightSubtreeId;

        bool operator==(const SubtreeKey& other) const {
            return value == other.value &&
                   leftSubtreeId == other.leftSubtreeId &&
                   rightSubtreeId == other.rightSubtreeId;
        }
    };

    struct SubtreeKeyHash {
        size_t operator()(const SubtreeKey& key) const {
            size_t hashValue = hash<int>{}(key.value);

            hashValue ^= hash<int>{}(key.leftSubtreeId) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);

            hashValue ^= hash<int>{}(key.rightSubtreeId) + 0x9e3779b9 + (hashValue << 6) + (hashValue >> 2);

            return hashValue;
        }
    };

    unordered_map<SubtreeKey, int, SubtreeKeyHash> subtreeIds;
    int nextSubtreeId;

    int getSubtreeId(TreeNode* node, bool mirrored) {
        if (node == nullptr) {
            return 0;
        }

        int leftSubtreeId;
        int rightSubtreeId;

        if (!mirrored) {
            leftSubtreeId = getSubtreeId(node->left, false);
            rightSubtreeId = getSubtreeId(node->right, false);
        } else {
            leftSubtreeId = getSubtreeId(node->right, true);
            rightSubtreeId = getSubtreeId(node->left, true);
        }

        SubtreeKey currentSubtree = {node->val,leftSubtreeId,rightSubtreeId};

        auto existingSubtree = subtreeIds.find(currentSubtree);

        if (existingSubtree != subtreeIds.end()) {
            return existingSubtree->second;
        }

        int currentSubtreeId = nextSubtreeId;
        nextSubtreeId++;

        subtreeIds[currentSubtree] = currentSubtreeId;

        return currentSubtreeId;
    }

public:
    // O(n) average | O(n)
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        subtreeIds.clear();
        nextSubtreeId = 1;

        int leftSubtreeId = getSubtreeId(root->left, false);
        int mirroredRightSubtreeId = getSubtreeId(root->right, true);

        return leftSubtreeId == mirroredRightSubtreeId;
    }
};