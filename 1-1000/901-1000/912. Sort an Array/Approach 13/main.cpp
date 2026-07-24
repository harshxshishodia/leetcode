class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        for(int gap=size/2;gap>0;gap/=2) {
            for(int index=gap;index<size;index++) {
                int current=nums[index];
                int position=index;

                while(position>=gap&&nums[position-gap]>current) {
                    nums[position]=nums[position-gap];
                    position-=gap;
                }

                nums[position]=current;
            }
        }

        return nums;
    }
};
