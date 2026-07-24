class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        for(int pass=0;pass<size-1;pass++) {
            bool sorted=true;

            for(int index=0;index<size-pass-1;index++) {
                if(nums[index]>nums[index+1]) {
                    int temp=nums[index];
                    nums[index]=nums[index+1];
                    nums[index+1]=temp;

                    sorted=false;
                }
            }

            if(sorted)
                break;
        }

        return nums;
    }
};
