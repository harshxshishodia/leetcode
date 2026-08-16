class Spreadsheet {
    unordered_map<string, int> cellValuesMap;

    int parseCellValue(const string& token) {
        if (token.empty()) return 0;
        if (isalpha(token[0])) {
            return cellValuesMap.count(token) ? cellValuesMap[token] : 0;
        }
        return stoi(token);
    }

public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) {
        cellValuesMap[cell] = value;
    }

    void resetCell(string cell) {
        cellValuesMap.erase(cell);
    }

    int getValue(string formula) {
        string expression = formula.substr(1);
        int plusPosition = expression.find('+');
        string firstOperand = expression.substr(0, plusPosition);
        string secondOperand = expression.substr(plusPosition + 1);
        return parseCellValue(firstOperand) + parseCellValue(secondOperand);
    }
};
