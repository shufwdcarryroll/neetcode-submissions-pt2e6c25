/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0; // initialize before DFS
        dfs(root);
        return diameter;
    }

private:
    int diameter; // class member to track max diameter
    int dfs(TreeNode* node)
    {
        if(node == nullptr)
           return 0;

        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);

        diameter = max(diameter, leftDepth + rightDepth);

        return 1 + max(leftDepth,rightDepth);


    }
};
