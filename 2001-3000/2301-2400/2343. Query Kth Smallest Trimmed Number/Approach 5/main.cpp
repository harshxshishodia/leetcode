class Solution {
    bool isTrimmedLess(const vector<string>& nums,int first,int second,int trimLength) {
        int digitCount=nums[0].size();

        for(int pos=digitCount-trimLength;pos<digitCount;pos++) {
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

            auto compareForMinHeap=[&](int first,int second) {
                return isTrimmedLess(nums,second,first,trimLength);
            };

            priority_queue<int,vector<int>,decltype(compareForMinHeap)> minHeap(compareForMinHeap);

            for(int index=0;index<size;index++)
                minHeap.push(index);

            while(kth>1) {
                minHeap.pop();
                kth--;
            }

            answer.push_back(minHeap.top());
        }

        return answer;
    }
};
