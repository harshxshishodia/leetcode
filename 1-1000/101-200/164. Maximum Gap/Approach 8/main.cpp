class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        int minValue=*min_element(nums.begin(),nums.end());
        int maxValue=*max_element(nums.begin(),nums.end());

        if(minValue==maxValue)
            return 0;

        long long valueRange=(long long)maxValue-minValue;
        long long bucketWidth=(valueRange+size-2)/(size-1);
        int bucketCount=valueRange/bucketWidth+1;

        vector<int> bucketMin(bucketCount,INT_MAX);
        vector<int> bucketMax(bucketCount,INT_MIN);

        for(int value:nums) {
            int bucketIndex=((long long)value-minValue)/bucketWidth;
            bucketMin[bucketIndex]=min(bucketMin[bucketIndex],value);
            bucketMax[bucketIndex]=max(bucketMax[bucketIndex],value);
        }

        int maxGap=0;
        int previousMax=minValue;

        for(int bucketIndex=0;bucketIndex<bucketCount;bucketIndex++) {
            if(bucketMin[bucketIndex]==INT_MAX)
                continue;

            maxGap=max(maxGap,bucketMin[bucketIndex]-previousMax);
            previousMax=bucketMax[bucketIndex];
        }

        return maxGap;
    }
};
