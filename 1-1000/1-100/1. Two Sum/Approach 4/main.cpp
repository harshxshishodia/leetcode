class Solution {
public:
    // O(nlogn) | O(n)
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> arr;

        for(int i=0;i<nums.size();i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        int n = arr.size();

        for(int i=0;i<n;i++){

            int need = target - arr[i].first;

            int left = i+1;
            int right = n-1;

            while(left <= right){

                int mid = left + (right-left)/2;

                if(arr[mid].first == need){
                    return {arr[i].second, arr[mid].second};
                }
                else if(arr[mid].first < need){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }

        return {};
    }
};