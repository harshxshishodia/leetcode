class MajorityChecker {
    struct Node {
        int candidate;
        int count;
        Node(int c = 0, int cnt = 0) : candidate(c), count(cnt) {}
    };
    vector<Node> segmentTree;
    unordered_map<int, vector<int>> elementIndicesMap;
    int arraySize;

    Node mergeNodes(Node leftNode, Node rightNode) {
        if (leftNode.candidate == rightNode.candidate) {
            return Node(leftNode.candidate, leftNode.count + rightNode.count);
        }
        if (leftNode.count >= rightNode.count) {
            return Node(leftNode.candidate, leftNode.count - rightNode.count);
        }
        return Node(rightNode.candidate, rightNode.count - leftNode.count);
    }

    void buildTree(int nodeIndex, int left, int right, const vector<int>& arr) {
        if (left == right) {
            segmentTree[nodeIndex] = Node(arr[left], 1);
            return;
        }
        int mid = left + (right - left) / 2;
        buildTree(2 * nodeIndex + 1, left, mid, arr);
        buildTree(2 * nodeIndex + 2, mid + 1, right, arr);
        segmentTree[nodeIndex] = mergeNodes(segmentTree[2 * nodeIndex + 1], segmentTree[2 * nodeIndex + 2]);
    }

    Node queryTree(int nodeIndex, int left, int right, int queryLeft, int queryRight) {
        if (queryLeft > right || queryRight < left) {
            return Node(0, 0);
        }
        if (left >= queryLeft && right <= queryRight) {
            return segmentTree[nodeIndex];
        }
        int mid = left + (right - left) / 2;
        return mergeNodes(queryTree(2 * nodeIndex + 1, left, mid, queryLeft, queryRight),
                          queryTree(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight));
    }

    int countOccurrences(int candidate, int left, int right) {
        if (!elementIndicesMap.count(candidate)) return 0;
        const auto& indices = elementIndicesMap[candidate];
        auto leftIt = lower_bound(indices.begin(), indices.end(), left);
        auto rightIt = upper_bound(indices.begin(), indices.end(), right);
        return distance(leftIt, rightIt);
    }

public:
    MajorityChecker(vector<int>& arr) {
        arraySize = arr.size();
        segmentTree.assign(4 * arraySize, Node());
        for (int i = 0; i < arraySize; i++) {
            elementIndicesMap[arr[i]].push_back(i);
        }
        buildTree(0, 0, arraySize - 1, arr);
    }
    
    int query(int left, int right, int threshold) {
        Node candidateNode = queryTree(0, 0, arraySize - 1, left, right);
        if (candidateNode.candidate != 0 && countOccurrences(candidateNode.candidate, left, right) >= threshold) {
            return candidateNode.candidate;
        }
        return -1;
    }
};
