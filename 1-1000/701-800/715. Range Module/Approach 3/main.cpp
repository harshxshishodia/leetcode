class RangeModule {
    struct Node {
        Node* left;
        Node* right;
        int state;

        Node(int state) {
            left = nullptr;
            right = nullptr;
            this->state = state;
        }
    };

    Node* root;
    const int minimumCoordinate = 1;
    const int maximumCoordinate = 1000000000;

    void push(Node* node) {
        if (node->state == -1)
            return;

        if (node->left == nullptr)
            node->left = new Node(node->state);
        else
            node->left->state = node->state;

        if (node->right == nullptr)
            node->right = new Node(node->state);
        else
            node->right->state = node->state;

        node->state = -1;
    }

    void update(Node* node, int left, int right, int queryLeft, int queryRight, int state) {
        if (queryRight < left || right < queryLeft)
            return;

        if (queryLeft <= left && right <= queryRight) {
            node->state = state;
            return;
        }

        push(node);

        int middle = left + (right - left) / 2;
        update(node->left, left, middle, queryLeft, queryRight, state);
        update(node->right, middle + 1, right, queryLeft, queryRight, state);

        if (node->left->state == node->right->state)
            node->state = node->left->state;
        else
            node->state = -1;
    }

    bool query(Node* node, int left, int right, int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft)
            return true;

        if (node->state != -1)
            return node->state == 1;

        int middle = left + (right - left) / 2;
        return query(node->left, left, middle, queryLeft, queryRight) && query(node->right, middle + 1, right, queryLeft, queryRight);
    }

public:
    RangeModule() {
        root = new Node(0);
    }

    void addRange(int left, int right) {
        update(root, minimumCoordinate, maximumCoordinate, left, right - 1, 1);
    }

    bool queryRange(int left, int right) {
        return query(root, minimumCoordinate, maximumCoordinate, left, right - 1);
    }

    void removeRange(int left, int right) {
        update(root, minimumCoordinate, maximumCoordinate, left, right - 1, 0);
    }
};