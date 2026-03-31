class Solution {
private:
    vector<int> rightSideNode;

    void dfs(TreeNode* root, int level) {
        if (!root) return;
        
        // If this is the first node at this level, add it
        if (level == rightSideNode.size()) {
            rightSideNode.push_back(root->val);
        }
        
        // Recurse right first, then left
        dfs(root->right, level + 1);
        dfs(root->left, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return rightSideNode;
    }
};
