class MyLinkedList {
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* headSentinel;
    Node* tailSentinel;
    int listSize;

public:
    MyLinkedList() : listSize(0) {
        headSentinel = new Node(0);
        tailSentinel = new Node(0);
        headSentinel->next = tailSentinel;
        tailSentinel->prev = headSentinel;
    }

    int get(int index) {
        if (index < 0 || index >= listSize) return -1;
        Node* current;
        if (index < listSize / 2) {
            current = headSentinel->next;
            for (int i = 0; i < index; i++) current = current->next;
        } else {
            current = tailSentinel->prev;
            for (int i = 0; i < listSize - 1 - index; i++) current = current->prev;
        }
        return current->value;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(listSize, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > listSize) return;
        Node* successor;
        if (index < listSize / 2) {
            successor = headSentinel->next;
            for (int i = 0; i < index; i++) successor = successor->next;
        } else {
            successor = tailSentinel;
            for (int i = 0; i < listSize - index; i++) successor = successor->prev;
        }
        Node* predecessor = successor->prev;
        Node* newNode = new Node(val);
        newNode->prev = predecessor;
        newNode->next = successor;
        predecessor->next = newNode;
        successor->prev = newNode;
        listSize++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= listSize) return;
        Node* current;
        if (index < listSize / 2) {
            current = headSentinel->next;
            for (int i = 0; i < index; i++) current = current->next;
        } else {
            current = tailSentinel->prev;
            for (int i = 0; i < listSize - 1 - index; i++) current = current->prev;
        }
        Node* predecessor = current->prev;
        Node* successor = current->next;
        predecessor->next = successor;
        successor->prev = predecessor;
        delete current;
        listSize--;
    }
};
