class Solution {
    bool isSuperUgly(int number, const vector<int>& primes) {
        if (number <= 0) {
            return false;
        }

        for (int prime : primes) {
            while (number % prime == 0) {
                number /= prime;
            }
        }

        return number == 1;
    }

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int count = 0;
        int number = 0;

        while (count < n) {
            number++;

            if (isSuperUgly(number, primes)) {
                count++;
            }
        }

        return number;
    }
};
