class ATM {
    long long banknoteStock[5];
    const long long denominations[5] = {20, 50, 100, 200, 500};

public:
    ATM() {
        for (int i = 0; i < 5; i++) banknoteStock[i] = 0;
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            banknoteStock[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> banknotesToDispense(5, 0);
        long long remainingAmount = amount;

        for (int i = 4; i >= 0; i--) {
            long long count = min(banknoteStock[i], remainingAmount / denominations[i]);
            banknotesToDispense[i] = count;
            remainingAmount -= count * denominations[i];
        }

        if (remainingAmount != 0) {
            return {-1};
        }

        for (int i = 0; i < 5; i++) {
            banknoteStock[i] -= banknotesToDispense[i];
        }
        return banknotesToDispense;
    }
};
