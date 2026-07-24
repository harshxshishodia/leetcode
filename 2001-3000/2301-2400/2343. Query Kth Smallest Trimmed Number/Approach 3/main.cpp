class Solution {
    bool isTrimmedLess(const vector<string>& nums,int first,int second,int trimLength) {
        int digitCount=nums[0].size();

        for(int pos=digitCount-trimLength;pos<digitCount;pos++) {
            if(nums[first][pos]!=nums[second][pos])
                return nums[first][pos]<nums[second][pos];
        }

        return first<second;
    }

    void mergeRange(vector<int>& order,vector<int>& buffer,int left,int mid,int right,const vector<string>& nums,int trimLength) {
        int leftIndex=left;
        int rightIndex=mid+1;
        int writeIndex=left;

        while(leftIndex<=mid&&rightIndex<=right) {
            if(isTrimmedLess(nums,order[leftIndex],order[rightIndex],trimLength))
                buffer[writeIndex++]=order[leftIndex++];
            else
                buffer[writeIndex++]=order[rightIndex++];
        }

        while(leftIndex<=mid)
            buffer[writeIndex++]=order[leftIndex++];

        while(rightIndex<=right)
            buffer[writeIndex++]=order[rightIndex++];

        for(int index=left;index<=right;index++)
            order[index]=buffer[index];
    }

    void mergeSort(vector<int>& order,vector<int>& buffer,int left,int right,const vector<string>& nums,int trimLength) {
        if(left>=right)
            return;

        int mid=left+(right-left)/2;

        mergeSort(order,buffer,left,mid,nums,trimLength);
        mergeSort(order,buffer,mid+1,right,nums,trimLength);
        mergeRange(order,buffer,left,mid,right,nums,trimLength);
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        vector<int> answer;

        for(auto& query:queries) {
            int kth=query[0];
            int trimLength=query[1];
            vector<int> order(size);
            vector<int> buffer(size);

            iota(order.begin(),order.end(),0);
            mergeSort(order,buffer,0,size-1,nums,trimLength);
            answer.push_back(order[kth-1]);
        }

        return answer;
    }
};
