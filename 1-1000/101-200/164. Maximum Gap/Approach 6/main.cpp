class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        vector<int> output(size);

        for(int shift=0;shift<32;shift+=8) {
            int counts[256]={};

            for(int value:nums)
                counts[(value>>shift)&255]++;

            for(int i=1;i<256;i++)
                counts[i]+=counts[i-1];

            for(int i=size-1;i>=0;i--) {
                int digit=(nums[i]>>shift)&255;
                output[--counts[digit]]=nums[i];
            }

            nums.swap(output);
        }

        int maxGap=0;

        for(int index=1;index<size;index++)
            maxGap=max(maxGap,nums[index]-nums[index-1]);

        return maxGap;
    }
};
