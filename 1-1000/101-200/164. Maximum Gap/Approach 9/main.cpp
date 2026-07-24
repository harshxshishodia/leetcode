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

        vector<int> bucketMin(size+1,INT_MAX);
        vector<int> bucketMax(size+1,INT_MIN);
        vector<bool> used(size+1,false);

        long long valueRange=(long long)maxValue-minValue;

        for(int value:nums) {
            int bucketIndex=(long long)(value-minValue)*size/valueRange;

            bucketMin[bucketIndex]=min(bucketMin[bucketIndex],value);
            bucketMax[bucketIndex]=max(bucketMax[bucketIndex],value);
            used[bucketIndex]=true;
        }

        int maxGap=0;
        int previousMax=minValue;

        for(int bucketIndex=0;bucketIndex<=size;bucketIndex++) {
            if(!used[bucketIndex])
                continue;

            maxGap=max(maxGap,bucketMin[bucketIndex]-previousMax);
            previousMax=bucketMax[bucketIndex];
        }

        return maxGap;
    }
};
