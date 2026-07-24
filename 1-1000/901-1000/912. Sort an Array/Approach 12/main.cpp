class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int> sortedValues;

        for(int value:nums)
            sortedValues.insert(value);

        int writeIndex=0;

        for(int value:sortedValues)
            nums[writeIndex++]=value;

        return nums;
    }
};
