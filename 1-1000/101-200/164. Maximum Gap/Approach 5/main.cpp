class Solution {
    void sortByDigit(vector<int>& values,long long place) {
        int size=values.size();
        vector<int> output(size);
        int counts[10]={};

        for(int value:values) {
            int digit=(value/place)%10;
            counts[digit]++;
        }

        for(int i=1;i<10;i++)
            counts[i]+=counts[i-1];

        for(int i=size-1;i>=0;i--) {
            int digit=(values[i]/place)%10;
            output[--counts[digit]]=values[i];
        }

        values.swap(output);
    }

public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        int maxValue=*max_element(nums.begin(),nums.end());

        for(long long place=1;maxValue/place>0;place*=10)
            sortByDigit(nums,place);

        int maxGap=0;

        for(int index=1;index<size;index++)
            maxGap=max(maxGap,nums[index]-nums[index-1]);

        return maxGap;
    }
};
