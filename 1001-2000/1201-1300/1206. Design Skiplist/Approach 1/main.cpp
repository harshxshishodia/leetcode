class Skiplist {
    static const int MAX_LEVEL = 16;
    struct SkipNode {
        int val;
        vector<SkipNode*> forward;
        SkipNode(int v, int level) : val(v), forward(level, nullptr) {}
    };

    SkipNode* head;
    int currentLevel;

    int randomLevel() {
        int lvl = 1;
        while ((rand() & 1) && lvl < MAX_LEVEL) {
            lvl++;
        }
        return lvl;
    }

public:
    Skiplist() : currentLevel(1) {
        head = new SkipNode(-1, MAX_LEVEL);
    }

    bool search(int target) {
        SkipNode* curr = head;
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        return curr && curr->val == target;
    }

    void add(int num) {
        vector<SkipNode*> update(MAX_LEVEL, nullptr);
        SkipNode* curr = head;
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }

        int lvl = randomLevel();
        if (lvl > currentLevel) {
            for (int i = currentLevel; i < lvl; i++) {
                update[i] = head;
            }
            currentLevel = lvl;
        }

        SkipNode* newNode = new SkipNode(num, lvl);
        for (int i = 0; i < lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool erase(int num) {
        vector<SkipNode*> update(MAX_LEVEL, nullptr);
        SkipNode* curr = head;
        for (int i = currentLevel - 1; i >= 0; i--) {
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }

        curr = curr->forward[0];
        if (!curr || curr->val != num) return false;

        for (int i = 0; i < currentLevel; i++) {
            if (update[i]->forward[i] != curr) break;
            update[i]->forward[i] = curr->forward[i];
        }
        delete curr;

        while (currentLevel > 1 && head->forward[currentLevel - 1] == nullptr) {
            currentLevel--;
        }
        return true;
    }
};
