class Solution {
    void sortByDigit(vector<int>& values,long long place) {
        int size=values.size();
        vector<int> output(size);
        int counts[10]={};

        for(int value:values)
            counts[(value/place)%10]++;

        for(int i=1;i<10;i++)
            counts[i]+=counts[i-1];

        for(int i=size-1;i>=0;i--) {
            int digit=(values[i]/place)%10;
            output[--counts[digit]]=values[i];
        }

        values.swap(output);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int minValue=nums[0];

        for(int value:nums) {
            if(value<minValue)
                minValue=value;
        }

        for(int& value:nums)
            value-=minValue;

        int maxValue=nums[0];

        for(int value:nums) {
            if(value>maxValue)
                maxValue=value;
        }

        for(long long place=1;maxValue/place>0;place*=10)
            sortByDigit(nums,place);

        for(int& value:nums)
            value+=minValue;

        return nums;
    }
};
