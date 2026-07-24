class Solution {
    bool isTrimmedLess(const vector<string>& nums,int first,int second,int trimLength) {
        int digitCount=nums[0].size();
        int start=digitCount-trimLength;

        for(int pos=start;pos<digitCount;pos++) {
            if(nums[first][pos]!=nums[second][pos])
                return nums[first][pos]<nums[second][pos];
        }

        return first<second;
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        vector<int> answer;

        for(auto& query:queries) {
            int kth=query[0];
            int trimLength=query[1];
            vector<int> order(size);

            iota(order.begin(),order.end(),0);

            sort(order.begin(),order.end(),[&](int first,int second) {
                return isTrimmedLess(nums,first,second,trimLength);
            });

            answer.push_back(order[kth-1]);
        }

        return answer;
    }
};
