class MRUQueue {
    vector<vector<int>> sqrtBlocks;
    int blockSize;

public:
    MRUQueue(int n) {
        blockSize = max(1, static_cast<int>(sqrt(n)));
        vector<int> currentBlock;
        for (int i = 1; i <= n; i++) {
            currentBlock.push_back(i);
            if (static_cast<int>(currentBlock.size()) == blockSize) {
                sqrtBlocks.push_back(currentBlock);
                currentBlock.clear();
            }
        }
        if (!currentBlock.empty()) {
            sqrtBlocks.push_back(currentBlock);
        }
    }

    int fetch(int k) {
        k--; // 0-based index
        int blockIndex = 0;
        while (blockIndex < static_cast<int>(sqrtBlocks.size()) && k >= static_cast<int>(sqrtBlocks[blockIndex].size())) {
            k -= sqrtBlocks[blockIndex].size();
            blockIndex++;
        }

        int val = sqrtBlocks[blockIndex][k];
        sqrtBlocks[blockIndex].erase(sqrtBlocks[blockIndex].begin() + k);

        for (int i = blockIndex; i + 1 < static_cast<int>(sqrtBlocks.size()); i++) {
            sqrtBlocks[i].push_back(sqrtBlocks[i + 1].front());
            sqrtBlocks[i + 1].erase(sqrtBlocks[i + 1].begin());
        }

        sqrtBlocks.back().push_back(val);
        return val;
    }
};
