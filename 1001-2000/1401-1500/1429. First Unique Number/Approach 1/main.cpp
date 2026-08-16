class FirstUnique {
    queue<int> orderQueue;
    unordered_map<int, int> frequencyMap;

public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }

    int showFirstUnique() {
        while (!orderQueue.empty() && frequencyMap[orderQueue.front()] > 1) {
            orderQueue.pop();
        }
        return orderQueue.empty() ? -1 : orderQueue.front();
    }

    void add(int value) {
        frequencyMap[value]++;
        if (frequencyMap[value] == 1) {
            orderQueue.push(value);
        }
    }
};
