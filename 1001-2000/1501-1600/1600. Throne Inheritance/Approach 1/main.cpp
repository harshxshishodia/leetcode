class ThroneInheritance {
    string kingName;
    unordered_map<string, vector<string>> royalFamilyTree;
    unordered_set<string> deadMembers;

    void dfsPreorder(const string& currentPerson, vector<string>& inheritanceList) {
        if (!deadMembers.count(currentPerson)) {
            inheritanceList.push_back(currentPerson);
        }
        auto it = royalFamilyTree.find(currentPerson);
        if (it != royalFamilyTree.end()) {
            for (const string& child : it->second) {
                dfsPreorder(child, inheritanceList);
            }
        }
    }

public:
    ThroneInheritance(string king) : kingName(king) {}

    void birth(string parentName, string childName) {
        royalFamilyTree[parentName].push_back(childName);
    }

    void death(string name) {
        deadMembers.insert(name);
    }

    vector<string> getInheritanceOrder() {
        vector<string> inheritanceList;
        dfsPreorder(kingName, inheritanceList);
        return inheritanceList;
    }
};
