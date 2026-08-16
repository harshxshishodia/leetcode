class Solution {
    pair<long long, long long> fibonacci(int n) {
        if (n == 0) {
            return {0, 1};
        }

        auto half = fibonacci(n / 2);
        long long first = half.first;
        long long second = half.second;
        long long doubledEven = first * (2 * second - first);
        long long doubledOdd = first * first + second * second;

        if (n % 2 == 0) {
            return {doubledEven, doubledOdd};
        }

        return {doubledOdd, doubledEven + doubledOdd};
    }

public:
    int fib(int n) {
        return static_cast<int>(fibonacci(n).first);
    }
};
