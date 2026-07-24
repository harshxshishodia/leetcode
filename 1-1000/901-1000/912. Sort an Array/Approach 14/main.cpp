class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        for(int index=1;index<size;index++) {
            int current=nums[index];
            int position=index-1;

            while(position>=0&&nums[position]>current) {
                nums[position+1]=nums[position];
                position--;
            }

            nums[position+1]=current;
        }

        return nums;
    }
};
