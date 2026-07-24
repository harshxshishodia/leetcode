class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        int digitCount=nums[0].size();
        int queryCount=queries.size();
        int maxTrim=0;

        vector<vector<int>> queryIdsByTrim(digitCount+1);

        for(int queryId=0;queryId<queryCount;queryId++) {
            int trimLength=queries[queryId][1];
            queryIdsByTrim[trimLength].push_back(queryId);
            maxTrim=max(maxTrim,trimLength);
        }

        vector<int> order(size);
        vector<int> buffer(size);
        vector<int> answer(queryCount);

        iota(order.begin(),order.end(),0);

        for(int trimLength=1;trimLength<=maxTrim;trimLength++) {
            int digitPos=digitCount-trimLength;
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

            for(int queryId:queryIdsByTrim[trimLength])
                answer[queryId]=order[queries[queryId][0]-1];
        }

        return answer;
    }
};
