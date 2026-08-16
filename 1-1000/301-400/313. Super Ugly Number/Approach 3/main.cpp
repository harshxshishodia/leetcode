class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int count = static_cast<int>(primes.size());
        vector<long long> ugly(n);
        vector<int> index(count);
        vector<long long> candidate(count);

        ugly[0] = 1;

        for (int i = 0; i < count; i++) {
            candidate[i] = primes[i];
        }

        for (int position = 1; position < n; position++) {
            long long next = *min_element(
                candidate.begin(),
                candidate.end()
            );

            ugly[position] = next;

            for (int i = 0; i < count; i++) {
                if (candidate[i] == next) {
                    index[i]++;
                    candidate[i] =
                        ugly[index[i]] * primes[i];
                }
            }
        }

        return static_cast<int>(ugly[n - 1]);
    }
};
