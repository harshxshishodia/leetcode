class Solution {
public:
    bool canWin(string currentState) {
        int n = static_cast<int>(currentState.size());
        vector<int> grundy(n + 1);

        for (int length = 2; length <= n; length++) {
            unordered_set<int> reachable;

            for (int split = 0; split + 1 < length; split++) {
                int leftLength = split;
                int rightLength = length - split - 2;
                reachable.insert(
                    grundy[leftLength] ^ grundy[rightLength]
                );
            }

            int value = 0;

            while (reachable.count(value)) {
                value++;
            }

            grundy[length] = value;
        }

        int total = 0;
        int runLength = 0;

        for (int i = 0; i <= n; i++) {
            if (i < n && currentState[i] == '+') {
                runLength++;
            } else {
                total ^= grundy[runLength];
                runLength = 0;
            }
        }

        return total != 0;
    }
};
