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

    int getSubtreeId(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftSubtreeId = getSubtreeId(node->left);
        int rightSubtreeId = getSubtreeId(node->right);

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        subtreeIds.clear();
        nextSubtreeId = 1;

        int firstTreeId = getSubtreeId(p);
        int secondTreeId = getSubtreeId(q);

        return firstTreeId == secondTreeId;
    }
};