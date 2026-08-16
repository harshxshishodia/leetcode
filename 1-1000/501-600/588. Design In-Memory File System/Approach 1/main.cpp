class FileSystem {
    struct FileNode {
        bool isDirectory = true;
        string content = "";
        map<string, FileNode*> children;
    };

    FileNode* root;

    vector<string> splitPath(const string& path) {
        vector<string> parts;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (!part.empty()) {
                parts.push_back(part);
            }
        }
        return parts;
    }

public:
    FileSystem() {
        root = new FileNode();
    }

    vector<string> ls(string path) {
        auto parts = splitPath(path);
        FileNode* curr = root;
        for (const string& p : parts) {
            curr = curr->children[p];
        }
        if (!curr->isDirectory) {
            return {parts.back()};
        }
        vector<string> res;
        for (const auto& [name, node] : curr->children) {
            res.push_back(name);
        }
        return res;
    }

    void mkdir(string path) {
        auto parts = splitPath(path);
        FileNode* curr = root;
        for (const string& p : parts) {
            if (!curr->children.count(p)) {
                curr->children[p] = new FileNode();
            }
            curr = curr->children[p];
        }
    }

    void addContentToFile(string filePath, string content) {
        auto parts = splitPath(filePath);
        FileNode* curr = root;
        for (int i = 0; i < static_cast<int>(parts.size()) - 1; i++) {
            if (!curr->children.count(parts[i])) {
                curr->children[parts[i]] = new FileNode();
            }
            curr = curr->children[parts[i]];
        }
        string fileName = parts.back();
        if (!curr->children.count(fileName)) {
            curr->children[fileName] = new FileNode();
            curr->children[fileName]->isDirectory = false;
        }
        curr->children[fileName]->content += content;
    }

    string readContentFromFile(string filePath) {
        auto parts = splitPath(filePath);
        FileNode* curr = root;
        for (const string& p : parts) {
            curr = curr->children[p];
        }
        return curr->content;
    }
};
