class FileSystem {
    unordered_map<string, int> pathMap;

public:
    FileSystem() {
        pathMap[""] = 0;
    }

    bool createPath(string path, int value) {
        if (path.empty() || path == "/" || pathMap.count(path)) {
            return false;
        }
        int lastSlash = path.find_last_of('/');
        string parentPath = path.substr(0, lastSlash);
        if (!pathMap.count(parentPath)) {
            return false;
        }
        pathMap[path] = value;
        return true;
    }

    int get(string path) {
        auto it = pathMap.find(path);
        return it != pathMap.end() ? it->second : -1;
    }
};
