class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        using Entry = tuple<long long, int, int>;

        priority_queue<
            Entry,
            vector<Entry>,
            greater<Entry>
        > minimumHeap;

        vector<long long> ugly(n);
        ugly[0] = 1;

        for (int prime : primes) {
            minimumHeap.push({prime, prime, 0});
        }

        for (int position = 1; position < n; position++) {
            long long next = get<0>(minimumHeap.top());
            ugly[position] = next;

            while (!minimumHeap.empty() &&
                   get<0>(minimumHeap.top()) == next) {
                auto [value, prime, index] = minimumHeap.top();
                minimumHeap.pop();

                index++;
                minimumHeap.push({
                    ugly[index] * prime,
                    prime,
                    index
                });
            }
        }

        return static_cast<int>(ugly[n - 1]);
    }
};
