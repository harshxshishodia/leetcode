class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(int value:nums)
            minHeap.push(value);

        int writeIndex=0;

        while(!minHeap.empty()) {
            nums[writeIndex++]=minHeap.top();
            minHeap.pop();
        }

        return nums;
    }
};
