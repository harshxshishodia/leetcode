class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        for(int index=0;index<size;index++) {
            int minIndex=index;

            for(int scan=index+1;scan<size;scan++) {
                if(nums[scan]<nums[minIndex])
                    minIndex=scan;
            }

            int temp=nums[index];
            nums[index]=nums[minIndex];
            nums[minIndex]=temp;
        }

        return nums;
    }
};
