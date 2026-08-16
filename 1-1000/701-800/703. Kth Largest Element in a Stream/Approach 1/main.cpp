class KthLargest {
    vector<int> elements;
    int kRank;

public:
    KthLargest(int k, vector<int>& nums) : elements(nums), kRank(k) {}

    int add(int val) {
        elements.push_back(val);
        sort(elements.begin(), elements.end(), greater<int>());
        return elements[kRank - 1];
    }
};
