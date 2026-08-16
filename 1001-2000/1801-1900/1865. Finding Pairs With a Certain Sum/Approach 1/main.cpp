class FindSumPairs {
    vector<int> array1;
    vector<int> array2;
    unordered_map<int, int> array2Frequency;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : array1(nums1), array2(nums2) {
        for (int num : nums2) {
            array2Frequency[num]++;
        }
    }

    void add(int index, int val) {
        array2Frequency[array2[index]]--;
        array2[index] += val;
        array2Frequency[array2[index]]++;
    }

    int count(int tot) {
        int pairCount = 0;
        for (int num : array1) {
            int complement = tot - num;
            auto it = array2Frequency.find(complement);
            if (it != array2Frequency.end()) {
                pairCount += it->second;
            }
        }
        return pairCount;
    }
};
