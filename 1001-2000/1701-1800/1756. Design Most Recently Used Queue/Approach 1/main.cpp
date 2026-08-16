class MRUQueue {
    vector<int> queueElements;

public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            queueElements.push_back(i);
        }
    }

    int fetch(int k) {
        int val = queueElements[k - 1];
        queueElements.erase(queueElements.begin() + k - 1);
        queueElements.push_back(val);
        return val;
    }
};
