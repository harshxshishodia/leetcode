class Solution {
    void mergeRange(vector<int>& values,vector<int>& buffer,int left,int mid,int right) {
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
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> buffer(size);

        for(int width=1;width<size;width*=2) {
            for(int left=0;left+width<size;left+=2*width) {
                int mid=left+width-1;
                int right=left+2*width-1;

                if(right>=size)
                    right=size-1;

                mergeRange(nums,buffer,left,mid,right);
            }
        }

        return nums;
    }
};
