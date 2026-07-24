class Solution {
    void sortByDigit(vector<int>& order,vector<int>& buffer,const vector<string>& nums,int digitPos) {
        int size=order.size();
        int counts[10]={};

        for(int index:order)
            counts[nums[index][digitPos]-'0']++;

        for(int i=1;i<10;i++)
            counts[i]+=counts[i-1];

        for(int i=size-1;i>=0;i--) {
            int digit=nums[order[i]][digitPos]-'0';
            buffer[--counts[digit]]=order[i];
        }

        order.swap(buffer);
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        int digitCount=nums[0].size();
        vector<int> answer;

        for(auto& query:queries) {
            int kth=query[0];
            int trimLength=query[1];
            vector<int> order(size);
            vector<int> buffer(size);

            iota(order.begin(),order.end(),0);

            for(int digitPos=digitCount-1;digitPos>=digitCount-trimLength;digitPos--)
                sortByDigit(order,buffer,nums,digitPos);

            answer.push_back(order[kth-1]);
        }

        return answer;
    }
};
