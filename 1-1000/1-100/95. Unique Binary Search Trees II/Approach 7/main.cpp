// Approach 7: Generate binary tree shapes and assign values using inorder traversal

class Solution {
private:
    vector<vector<TreeNode*>> shapeMemo;
    vector<bool> shapeComputed;

    vector<TreeNode*> generateShapes(int nodeCount) {
        if (shapeComputed[nodeCount]) {
            return shapeMemo[nodeCount];
        }

        vector<TreeNode*> allShapes;

        for (int leftNodeCount = 0; leftNodeCount < nodeCount; leftNodeCount++) {
            int rightNodeCount = nodeCount - leftNodeCount - 1;

            vector<TreeNode*> leftShapes = generateShapes(leftNodeCount);

            vector<TreeNode*> rightShapes = generateShapes(rightNodeCount);

            for (TreeNode* leftShape : leftShapes) {
                for (TreeNode* rightShape : rightShapes) {
                    TreeNode* root = new TreeNode(0);

                    root->left = leftShape;
                    root->right = rightShape;

                    allShapes.push_back(root);
                }
            }
        }

        shapeComputed[nodeCount] = true;
        shapeMemo[nodeCount] = allShapes;

        return shapeMemo[nodeCount];
    }

    TreeNode* cloneAndAssignValues(TreeNode* shape,int& nextValue) {
        if (shape == nullptr) {
            return nullptr;
        }

        TreeNode* leftSubtree = cloneAndAssignValues(shape->left, nextValue);

        TreeNode* root = new TreeNode(nextValue);
        nextValue++;

        TreeNode* rightSubtree = cloneAndAssignValues(shape->right, nextValue);

        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }

public:
    // O(n * Cn) | O(n * Cn)
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        shapeMemo.assign(n + 1,vector<TreeNode*>());

        shapeComputed.assign(n + 1, false);

        shapeMemo[0].push_back(nullptr);
        shapeComputed[0] = true;

        vector<TreeNode*> allShapes = generateShapes(n);

        vector<TreeNode*> allTrees;

        for (TreeNode* shape : allShapes) {
            int nextValue = 1;

            allTrees.push_back(cloneAndAssignValues(shape, nextValue));
        }

        return allTrees;
    }
};