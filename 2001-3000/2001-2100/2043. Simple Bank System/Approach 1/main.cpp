class Bank {
    vector<long long> accountBalances;
    int accountCount;

    bool isValidAccount(int account) {
        return account >= 1 && account <= accountCount;
    }

public:
    Bank(vector<long long>& balance) : accountBalances(balance), accountCount(static_cast<int>(balance.size())) {}

    bool transfer(int account1, int account2, long long money) {
        if (!isValidAccount(account1) || !isValidAccount(account2)) return false;
        if (accountBalances[account1 - 1] < money) return false;
        accountBalances[account1 - 1] -= money;
        accountBalances[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValidAccount(account)) return false;
        accountBalances[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValidAccount(account)) return false;
        if (accountBalances[account - 1] < money) return false;
        accountBalances[account - 1] -= money;
        return true;
    }
};
