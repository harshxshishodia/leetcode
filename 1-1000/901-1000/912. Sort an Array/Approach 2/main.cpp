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

    void mergeSort(vector<int>& values,vector<int>& buffer,int left,int right) {
        if(left>=right)
            return;

        int mid=left+(right-left)/2;

        mergeSort(values,buffer,left,mid);
        mergeSort(values,buffer,mid+1,right);
        mergeRange(values,buffer,left,mid,right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> buffer(size);

        mergeSort(nums,buffer,0,size-1);

        return nums;
    }
};
