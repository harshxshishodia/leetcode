class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        int minValue=*min_element(nums.begin(),nums.end());
        int maxValue=*max_element(nums.begin(),nums.end());
        long long valueRange=(long long)maxValue-minValue;

        vector<char> present(valueRange+1,false);

        for(int value:nums)
            present[value-minValue]=true;

        int maxGap=0;
        long long previousOffset=-1;

        for(long long offset=0;offset<=valueRange;offset++) {
            if(!present[offset])
                continue;

            if(previousOffset!=-1)
                maxGap=max(maxGap,(int)(offset-previousOffset));

            previousOffset=offset;
        }

        return maxGap;
    }
};
