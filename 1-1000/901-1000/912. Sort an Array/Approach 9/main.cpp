class Solution {
    void insertionSort(vector<int>& bucket) {
        for(int index=1;index<bucket.size();index++) {
            int current=bucket[index];
            int position=index-1;

            while(position>=0&&bucket[position]>current) {
                bucket[position+1]=bucket[position];
                position--;
            }

            bucket[position+1]=current;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return nums;

        int minValue=nums[0];
        int maxValue=nums[0];

        for(int value:nums) {
            if(value<minValue)
                minValue=value;

            if(value>maxValue)
                maxValue=value;
        }

        if(minValue==maxValue)
            return nums;

        int bucketWidth=(maxValue-minValue)/size+1;
        int bucketCount=(maxValue-minValue)/bucketWidth+1;
        vector<vector<int>> buckets(bucketCount);

        for(int value:nums)
            buckets[(value-minValue)/bucketWidth].push_back(value);

        int writeIndex=0;

        for(int bucketIndex=0;bucketIndex<bucketCount;bucketIndex++) {
            insertionSort(buckets[bucketIndex]);

            for(int value:buckets[bucketIndex])
                nums[writeIndex++]=value;
        }

        return nums;
    }
};
