class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
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

            for (int prime : primes) {
                long long next = current * prime;

                if (next <= numeric_limits<int>::max() &&
                    seen.insert(next).second) {
                    minimumHeap.push(next);
                }
            }
        }

        return static_cast<int>(current);
    }
};
