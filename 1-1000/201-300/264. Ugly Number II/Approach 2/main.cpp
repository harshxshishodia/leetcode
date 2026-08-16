class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<
            long long,
            vector<long long>,
            greater<long long>
        > minimumHeap;

        unordered_set<long long> seen;
        minimumHeap.push(1);
        seen.insert(1);
        long long current = 1;

        for (int i = 0; i < n; i++) {
            current = minimumHeap.top();
            minimumHeap.pop();

            for (long long factor : {2LL, 3LL, 5LL}) {
                long long next = current * factor;

                if (seen.insert(next).second) {
                    minimumHeap.push(next);
                }
            }
        }

        return static_cast<int>(current);
    }
};
