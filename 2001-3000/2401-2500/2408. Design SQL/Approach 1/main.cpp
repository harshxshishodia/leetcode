class SQL {
    unordered_map<string, unordered_map<int, vector<string>>> tablesMap;
    unordered_map<string, int> nextRowIdMap;
    unordered_map<string, int> expectedColumnCounts;

public:
    SQL(vector<string>& names, vector<int>& columns) {
        for (int i = 0; i < static_cast<int>(names.size()); i++) {
            expectedColumnCounts[names[i]] = columns[i];
            nextRowIdMap[names[i]] = 1;
        }
    }

    bool ins(string name, vector<string> row) {
        if (!expectedColumnCounts.count(name) || static_cast<int>(row.size()) != expectedColumnCounts[name]) {
            return false;
        }
        int rowId = nextRowIdMap[name]++;
        tablesMap[name][rowId] = row;
        return true;
    }

    void rmv(string name, int rowId) {
        if (tablesMap.count(name)) {
            tablesMap[name].erase(rowId);
        }
    }

    string sel(string name, int rowId, int columnId) {
        if (!tablesMap.count(name) || !tablesMap[name].count(rowId)) {
            return "<null>";
        }
        const auto& rowData = tablesMap[name][rowId];
        if (columnId < 1 || columnId > static_cast<int>(rowData.size())) {
            return "<null>";
        }
        return rowData[columnId - 1];
    }

    vector<string> exp(string name) {
        vector<string> exportedRows;
        if (!tablesMap.count(name)) return exportedRows;

        for (int id = 1; id < nextRowIdMap[name]; id++) {
            if (tablesMap[name].count(id)) {
                stringstream ss;
                ss << id;
                for (const string& val : tablesMap[name][id]) {
                    ss << "," << val;
                }
                exportedRows.push_back(ss.str());
            }
        }
        return exportedRows;
    }
};
