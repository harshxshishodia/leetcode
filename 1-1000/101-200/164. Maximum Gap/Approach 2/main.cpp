class Solution {
    void mergeSort(vector<int>& values,vector<int>& buffer,int left,int right) {
        if(left>=right)
            return;

        int mid=left+(right-left)/2;

        mergeSort(values,buffer,left,mid);
        mergeSort(values,buffer,mid+1,right);

        int leftIndex=left;
        int rightIndex=mid+1;
        int writeIndex=left;

        while(leftIndex<=mid&&rightIndex<=right) {
            if(values[leftIndex]<=values[rightIndex])
                buffer[writeIndex++]=values[leftIndex++];
            else
                buffer[writeIndex++]=values[rightIndex++];
        }

        while(leftIndex<=mid)
            buffer[writeIndex++]=values[leftIndex++];

        while(rightIndex<=right)
            buffer[writeIndex++]=values[rightIndex++];

        for(int index=left;index<=right;index++)
            values[index]=buffer[index];
    }

public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        vector<int> buffer(size);

        mergeSort(nums,buffer,0,size-1);

        int maxGap=0;

        for(int index=1;index<size;index++)
            maxGap=max(maxGap,nums[index]-nums[index-1]);

        return maxGap;
    }
};
