class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minValue=nums[0];
        int maxValue=nums[0];

        for(int value:nums) {
            if(value<minValue)
                minValue=value;

            if(value>maxValue)
                maxValue=value;
        }

        vector<int> counts(maxValue-minValue+1,0);

        for(int value:nums)
            counts[value-minValue]++;

        int writeIndex=0;

        for(int offset=0;offset<counts.size();offset++) {
            while(counts[offset]>0) {
                nums[writeIndex++]=offset+minValue;
                counts[offset]--;
            }
        }

        return nums;
    }
};
