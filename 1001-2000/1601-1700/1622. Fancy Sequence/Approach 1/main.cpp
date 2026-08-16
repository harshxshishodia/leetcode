class Fancy {
    static const long long MOD = 1e9 + 7;
    vector<long long> rawElements;
    long long scaleMultiplier;
    long long offsetAdd;

    long long modInverse(long long base) {
        long long exp = MOD - 2;
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    Fancy() : scaleMultiplier(1), offsetAdd(0) {}

    void append(int val) {
        long long normalizedVal = ((val - offsetAdd) % MOD + MOD) % MOD;
        normalizedVal = (normalizedVal * modInverse(scaleMultiplier)) % MOD;
        rawElements.push_back(normalizedVal);
    }

    void addAll(int inc) {
        offsetAdd = (offsetAdd + inc) % MOD;
    }

    void multAll(int m) {
        scaleMultiplier = (scaleMultiplier * m) % MOD;
        offsetAdd = (offsetAdd * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= static_cast<int>(rawElements.size())) return -1;
        return (rawElements[idx] * scaleMultiplier + offsetAdd) % MOD;
    }
};
