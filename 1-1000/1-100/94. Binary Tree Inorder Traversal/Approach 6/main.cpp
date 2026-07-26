// Approach 6: Iterative DFS using traversal commands

class Solution {
private:
    enum CommandType {
        TRAVERSE,
        PROCESS
    };

    struct Command {
        TreeNode* node;
        CommandType type;
    };

public:
    // O(n) | O(h)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        if (root == nullptr) {
            return traversal;
        }

        stack<Command> commands;
        commands.push({root, TRAVERSE});

        while (!commands.empty()) {
            Command command = commands.top();
            commands.pop();

            TreeNode* currentNode = command.node;

            if (currentNode == nullptr) {
                continue;
            }

            if (command.type == PROCESS) {
                traversal.push_back(currentNode->val);
            } else {
                commands.push({currentNode->right, TRAVERSE});
                commands.push({currentNode, PROCESS});
                commands.push({currentNode->left, TRAVERSE});
            }
        }

        return traversal;
    }
};