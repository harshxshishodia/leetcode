class Solution {
    void radixSort(vector<int>& values,int left,int right,int bit) {
        if(left>=right||bit<0)
            return;

        int low=left;
        int high=right;

        while(low<=high) {
            while(low<=high&&((values[low]>>bit)&1)==0)
                low++;

            while(low<=high&&((values[high]>>bit)&1)==1)
                high--;

            if(low<=high) {
                swap(values[low],values[high]);
                low++;
                high--;
            }
        }

        radixSort(values,left,high,bit-1);
        radixSort(values,low,right,bit-1);
    }

public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        radixSort(nums,0,size-1,30);

        int maxGap=0;

        for(int index=1;index<size;index++)
            maxGap=max(maxGap,nums[index]-nums[index-1]);

        return maxGap;
    }
};
