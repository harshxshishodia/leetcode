class Solution {
    struct Node {
        int value;
        int priority;
        int frequency;
        int size;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            priority = rand();
            frequency = 1;
            size = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    int getSize(Node* node) {
        if (node == nullptr)
            return 0;

        return node->size;
    }

    void updateSize(Node* node) {
        if (node != nullptr)
            node->size = node->frequency + getSize(node->left) + getSize(node->right);
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        updateSize(node);
        updateSize(newRoot);
        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        updateSize(node);
        updateSize(newRoot);
        return newRoot;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value == node->value) {
            node->frequency++;
        } else if (value < node->value) {
            node->left = insert(node->left, value);

            if (node->left->priority > node->priority)
                node = rotateRight(node);
        } else {
            node->right = insert(node->right, value);

            if (node->right->priority > node->priority)
                node = rotateLeft(node);
        }

        updateSize(node);
        return node;
    }

    int countSmallerValues(Node* node, int value) {
        if (node == nullptr)
            return 0;

        if (value <= node->value)
            return countSmallerValues(node->left, value);

        return getSize(node->left) + node->frequency + countSmallerValues(node->right, value);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);
        Node* root = nullptr;

        for (int index = n - 1; index >= 0; index--) {
            answer[index] = countSmallerValues(root, nums[index]);
            root = insert(root, nums[index]);
        }

        return answer;
    }
};