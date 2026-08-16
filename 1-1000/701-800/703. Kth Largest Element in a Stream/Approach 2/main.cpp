class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kSize;

public:
    KthLargest(int k, vector<int>& nums) : kSize(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (static_cast<int>(minHeap.size()) > kSize) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
